/*
 * scoreboard.cpp
 *
 *  Created on: Nov 27, 2014
 *      Author: fred
 */

#include "scoreboard.h"
#include "register_lib.h"
#include <systemc.h>

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
	 */

	//FORM OPCODE
	sc_uint<7> opcode = 0;
	opcode = (instruct.F * 10) + instruct.m;

	//REGISTER ASSIGNMENT/MAPPING



} //end decode_short

void SCOREBOARD::issue_stage(void){

	//Check for structural hazard
	if (unit_stat_reg.){

	}


}//end issue_stage



