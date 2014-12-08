/*
 * scoreboard.cpp
 *
 *  Created on: Nov 27, 2014
 *      Author: fred
 */

#include "scoreboard.h"
#include "register_lib.h"
#include <systemc.h>



bool SCOREBOARD::check_data_haz(void){

	bool data_haz = false;
	int stages = 1;
	if(!is_CDC6600) {
		stages = 4;
	}
	for(int i=0; i<unit_stat_reg->num_units; i++) {
		for(int j=0; j<stages; j++) {
			if(unit_stat_reg->m_statusReg[i].instr_in_stage[j]) {
				if(cur_instr.m_source1 == unit_stat_reg->m_statusReg[i].dest_reg[j]) {
					return true;
				}
				else if (cur_instr.m_source2 == unit_stat_reg->m_statusReg[i].dest_reg[j] and cur_instr.m_source2 != k) {
					return true;
				}
			}
		}
	}
	return data_haz;

}//end check_data_haz

bool SCOREBOARD::check_unit_haz(void){
	bool unit_haz = false;

	switch (cur_instr.m_opcode) {
		case multiply:
			if(unit_stat_reg->m_statusReg[(int)cur_instr.m_opcode].busy and unit_stat_reg->m_statusReg[(int)cur_instr.m_opcode+1].busy)
				unit_haz = true;
			break;
		case increment:
			if(unit_stat_reg->m_statusReg[(int)cur_instr.m_opcode+1].busy and unit_stat_reg->m_statusReg[(int)cur_instr.m_opcode+2].busy)
				unit_haz = true;
			break;
		default:
			if(unit_stat_reg->m_statusReg[(int)cur_instr.m_opcode].busy)
				unit_haz = true;
	}

	return unit_haz;
}//end check_unit_haz


void SCOREBOARD::issue_stage(void){
	//check if we should wait before attempting issue. due to branch or long instr
	if (wait) {
		wait_time--;
		if(wait_time == 0) {
			wait = false;
			return;
		}
	}
	//Instruction current_instruct;
	if(fetch_instr) {
		if(fifo_buffer.nb_read(cur_instr)) {
			timing_table->m_issue[cur_instr.instr_count] = sig_clock_cycles;
			//cout << sc_time_stamp() << endl;
			//cout << cur_instr << endl;
			fetch_instr = false;
		}
		else {
			cout << sc_time_stamp() << " done sending instructions..waiting for them to complete" <<endl;
			count++;
			if(count>5)
				unit_stat_reg->instructions_done = true;
				return;
		}
	}

	//Check for conflicts
	bool unit_haz = SCOREBOARD::check_unit_haz();
	bool data_haz = SCOREBOARD::check_data_haz();

	//If no conflicts proceed to issue instruction
	if (!unit_haz && !data_haz){
		cout << sc_time_stamp() << " Starting Instruction" << endl;
		timing_table->m_start[cur_instr.instr_count] = sig_clock_cycles;

		switch (cur_instr.m_opcode) {
			case fixed_add: 
				unit_stat_reg->time_until_complete = m_fixed_add->cycle_delay;
				unit_stat_reg->time_until_free = m_fixed_add->time_until_free;
				unit_stat_reg->func_unit = fixed_adder;
				break;
			case float_add:
				unit_stat_reg->time_until_complete = m_floating_add->cycle_delay;
				unit_stat_reg->time_until_free = m_floating_add->time_until_free;
				unit_stat_reg->func_unit = float_adder;
				break;
			case boolean:
				unit_stat_reg->time_until_complete = m_bool->cycle_delay;
				unit_stat_reg->time_until_free = m_bool->time_until_free;
				unit_stat_reg->func_unit = bool_unit;
				break;
			case shift:
				unit_stat_reg->time_until_complete = m_shift->cycle_delay;
				unit_stat_reg->time_until_free = m_shift->time_until_free;
				unit_stat_reg->func_unit = shifter;
				break;
			case branch:
				unit_stat_reg->time_until_complete = m_branch->cycle_delay + 2;
				unit_stat_reg->time_until_free = m_branch->time_until_free;
				unit_stat_reg->func_unit = brancher;
				break;
			case divide:
				unit_stat_reg->time_until_complete = m_div->cycle_delay;
				unit_stat_reg->time_until_free = m_div->time_until_free;
				unit_stat_reg->func_unit = divider;
				break;
			case multiply:
				if(unit_stat_reg->m_statusReg[(int)cur_instr.m_opcode].busy)
					unit_stat_reg->func_unit = multiplier2;
				else
					unit_stat_reg->func_unit = multiplier1;
				unit_stat_reg->time_until_complete = m_mult->cycle_delay;
				unit_stat_reg->time_until_free = m_mult->time_until_free;
				break;
			case increment:
				if(unit_stat_reg->m_statusReg[(int)cur_instr.m_opcode+1].busy)
					unit_stat_reg->func_unit = incrementer2;
				else
					unit_stat_reg->func_unit = incrementer1;
				unit_stat_reg->time_until_complete = m_inc->cycle_delay;
				unit_stat_reg->time_until_free = m_inc->time_until_free;
				break;
			default:
				break;
			}

		if(cur_instr.m_source2 == k)
			timing_table->fetch[cur_instr.instr_count] = true;
			
		unit_stat_reg->dest_reg = cur_instr.m_destination;
		unit_stat_reg->cur_instr = cur_instr.instr_count;
		unit_stat_reg->add_request();
		
		fetch_instr = true;
		if(cur_instr.m_length == LONG) {
			wait = true;
			wait_time = 1;
		}
		else if (cur_instr.m_opcode == branch) {
			wait = true;
			wait_time = 14;
		}
		
	}//end hazard check




}//end issue_stage

