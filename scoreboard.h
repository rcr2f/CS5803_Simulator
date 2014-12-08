/*
 * scoreboard.h
 *
 *  Created on: Nov 27, 2014
 *      Author: fred
 * 				rebecca
 */

#ifndef SCOREBOARD_H_
#define SCOREBOARD_H_

#include <systemc.h>
#include "register_lib.cpp"
#include "functional_unit_lib.cpp"
#include "instruction.h"
#include "enums.h"
#include "timing_table.h"

SC_MODULE (SCOREBOARD){

	//ports, processes, internal data
	sc_in_clk clock;
	sc_inout< bool > end;
	sc_fifo<Instruction> fifo_buffer;
	sc_fifo<Instruction> hazard_buffer;
	sc_fifo<Operation> unit_select_buffer;
	sc_inout< bool > is_CDC6600;
	
	//functional units
	MULTIPLIER * m_mult;
	DIVIDER * m_div;
	FIXED_ADD * m_fixed_add;
	FLOATING_ADD * m_floating_add;
	INCREMENTER * m_inc;
	SHIFTER * m_shift;
	BOOLEAN * m_bool;
	BRANCHER * m_branch;
	
	//Functional unit status register - fred
	FUNC_UNIT_STATUS * unit_stat_reg;
	bool wait;
	int wait_time;
	Instruction cur_instr;
	bool fetch_instr;

	//Process declarations/prototypes
	void issue_stage(void);
	
	//Helper function declarations/prototypes
	bool check_unit_haz(void);
	bool check_data_haz(void);
	
	//output for timing table
	Timing_Table * timing_table;
	sc_inout< int > sig_clock_cycles;
	void init_timing_table() {
		unit_stat_reg->timing_table = timing_table;
	}
	
	//count for empty instruction buffer	
	int count;
	//keep track of which line to output timing table for
	int instr_count;

	//Constructor
	SC_CTOR(SCOREBOARD){

		fetch_instr = true;
		//attempt to issue every clock cycle
		SC_METHOD (issue_stage);
		sensitive << clock.pos();
		
		//Instruction input buffer
		sc_fifo<Instruction> fifo_buffer (2);
		sc_fifo<Instruction> hazard_buffer (32);
		sc_fifo<Operation> unit_select_buffer (32);
		
		//initializing functional units
		m_mult = new MULTIPLIER("Multiplier0");
		m_mult->clock(clock);
		m_mult->is_CDC6600(is_CDC6600);
		
		m_div = new DIVIDER("Divider0");
		m_div->clock(clock);;
		m_div->is_CDC6600(is_CDC6600);
		
		m_fixed_add = new FIXED_ADD("Fixed_Add0");
		m_fixed_add->clock(clock);
		m_fixed_add->is_CDC6600(is_CDC6600);
		
		m_floating_add = new FLOATING_ADD("Floating_Add0");
		m_floating_add->clock(clock);
		m_floating_add->is_CDC6600(is_CDC6600);
		
		m_inc = new INCREMENTER("Incrementer0");
		m_inc->clock(clock);
		m_inc->is_CDC6600(is_CDC6600);
		
		m_shift = new SHIFTER("Shifter0");
		m_shift->clock(clock);
		m_shift->is_CDC6600(is_CDC6600);
		
		m_bool = new BOOLEAN("Boolean0");
		m_bool->clock(clock);
		m_bool->is_CDC6600(is_CDC6600);
		
		m_branch = new BRANCHER("Brancher0");
		m_branch->clock(clock);
		m_branch->is_CDC6600(is_CDC6600);
		
		//Adding functional unit status register - fred
		unit_stat_reg = new FUNC_UNIT_STATUS ("Func_Unit_Status_Reg0");
		unit_stat_reg->clock(clock);
		unit_stat_reg->end(end);
		unit_stat_reg->sig_clock_cycles(sig_clock_cycles);
		unit_stat_reg->is_CDC6600(is_CDC6600);

		count = 0;
	}//end SC_CTOR

};//end SCOREBOARD




#endif /* SCOREBOARD_H_ */
