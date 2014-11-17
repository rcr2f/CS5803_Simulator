/*
 * functional_unit_top.cpp
 *
 *  Created on: Nov 16, 2014
 *      Author: fred
 */
#include <systemc.h>
#include "sc_module_lib.h"

/******************************
 *
 * Function:	FUNCTIONAL UNIT TOP MODULE
 * Author:		Fred Love
 * Created:		11/16/15
 * Modified:	N/A
 *
 *******************************/
SC_MODULE (functonal_unit_top) {

   //ports, processes, internal data
	multiplier mult1_unit;
	multiplier mult2_unit;
	incrementer inc1_unit;
	incrementer inc2_unit;
	fixed_add fixedA_unit;
	floating_add floatA_unit;
	divider div_unit;
	shifter shift_unit;
	boolean bool_unit;


   SC_CTOR (functional_unit_top){


   } //end SC_CTOR

}; //end functional_unit_top



