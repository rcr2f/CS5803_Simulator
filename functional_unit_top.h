/*
 * functional_unit_top.h
 *
 *  Created on: Nov 23, 2014
 *      Author: fred
 */

#ifndef FUNCTIONAL_UNIT_TOP_H_
#define FUNCTIONAL_UNIT_TOP_H_

#include <systemc.h>
#include "register_lib.h"
#include "functional_unit_lib.h"

/******************************
 *
 * Function:	FUNCTIONAL UNIT TOP MODULE
 * Author:		Fred Love
 * Created:		11/16/15
 * Modified:	N/A
 *
 *******************************/
SC_MODULE (FUNCTIONAL_UNIT_TOP) {

   //ports, processes, internal data
   sc_signal<int> op_reg_sig;


	//Process prototypes/declarations
	void update_unit_status(void);

	//Constructor
	SC_CTOR (FUNCTIONAL_UNIT_TOP){

		//Functional Unit instantiation
		MULTIPLIER mult1_unit ("Multiplier 1");
		MULTIPLIER mult2_unit ("Multiplier 2");
		INCREMENTER inc1_unit ("Incrementer 1");
		INCREMENTER inc2_unit ("Incrementer 2");
		FIXED_ADD fixedA_unit ("Fixed Adder");
		FLOATING_ADD floatA_unit ("Floating Point Adder");
		DIVIDER div_unit ("Divider");
		SHIFTER shift_unit ("Shifter");
		BOOLEAN bool_unit ("Boolean");
		BRANCHER branch_unit ("Brancher");

		//Functional Unit Operand Registers
		FUNC_OP_REGS op_reg ("Func Operand Reg");

		/*
		 * NEED CHANNEL BETWEEN UNITS AND REG
		 */


		//Register process with simulation kernel
		SC_METHOD(update_unit_status);

   } //end SC_CTOR

}; //end functional_unit_top



#endif /* FUNCTIONAL_UNIT_TOP_H_ */
