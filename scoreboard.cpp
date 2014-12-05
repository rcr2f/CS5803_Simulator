/*
 * scoreboard.cpp
 *
 *  Created on: Nov 27, 2014
 *      Author: fred
 */

#include "scoreboard.h"
#include "register_lib.h"
#include <systemc.h>

/*
void SCOREBOARD::decode_short(shortInstruct instruct){
	/*
	 * struct shortInstruct {
	//F+m = opcode
	//i,j,k = refer to one of A, X, B registers
	sc_uint<3> F;
	sc_uint<3> m;
	sc_uint<3> i;
	sc_uint<3> j;
	sc_uint<3> k;
};
	 

	//FORM OPCODE
	sc_uint<7> opcode = 0;
	opcode = (instruct.F * 10) + instruct.m;

	//REGISTER ASSIGNMENT/MAPPING



} //end decode_short*/

bool SCOREBOARD::check_data_haz(void){

	bool data_haz;
	Instruction next_instruction;
	hazard_buffer.nb_read(next_instruction);

	/*
	 * TODO - Perform check here
	 */


	return data_haz;

}//end check_data_haz

bool SCOREBOARD::check_unit_haz(void){

	bool unit_haz;
	Instruction next_instruction;
	fifo_buffer.nb_read(next_instruction);

	/*
	 * TODO - Perform check here
	 */


	hazard_buffer.write(next_instruction);
	return unit_haz;
}//end check_unit_haz


void SCOREBOARD::issue_stage(void){
	//Instruction current_instruct;

	//Check for conflicts
	bool unit_haz = SCOREBOARD::check_unit_haz();
	bool data_haz = SCOREBOARD::check_data_haz();

	//If no conflicts proceed to issue instruction
	/*
	 * NOTE TO REBECCA - Would it be better to use case statements?  To address
	 *                   when we have only one hazard?
	 */
	if (!unit_haz && !data_haz){

	}//end hazard check




}//end issue_stage

