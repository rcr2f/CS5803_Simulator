/*
 * functional_unit_lib.cpp
 *
 *  Created on: Nov 22, 2014
 *      Author: fred
 */

#include <systemc.h>
#include "functional_unit_lib.h"
#include "register_lib.h"

/******************************
 *
 * Function:	MULTIPLIER MODULE
 * Author:		Fred Love
 * Created:		11/16/15
 * Modified:	N/A
 *
 *******************************/
void MULTIPLIER::multiply(void){

	//update status register to busy
	//increment simulation time by 10 cycles
	//update status register to available
	multiply_busy.notify();
	multiply_complete.notify();
	multiply_available.notify();

}//end multiply


/******************************
 *
 * Function:	DIVIDER MODULE
 * Author:		Fred Love
 * Created:		11/16/15
 * Modified:	N/A
 *
 *******************************/
void DIVIDER::divide(void){

	divide_busy.notify();
	divide_complete.notify();
	divide_available.notify();

}//end divide


/******************************
 *
 * Function:	FIXED_ADD MODULE
 * Author:		Fred Love
 * Created:		11/16/15
 * Modified:	N/A
 *
 *******************************/
void FIXED_ADD::add(void){

	fixed_add_busy.notify();
	fixed_add_complete.notify();
	fixed_add_available.notify();

}//end add


/******************************
 *
 * Function:	FLOATING_ADD MODULE
 * Author:		Fred Love
 * Created:		11/16/15
 * Modified:	N/A
 *
 *******************************/
void FLOATING_ADD::add(void){

	float_add_busy.notify();
	float_add_complete.notify();
	float_add_available.notify();

}//end add


/******************************
 *
 * Function:	INCREMENTER MODULE
 * Author:		Fred Love
 * Created:		11/16/15
 * Modified:	N/A
 *
 *******************************/
void INCREMENTER::increment(void){

	increment_busy.notify();
	increment_complete.notify();
	increment_available.notify();

}//end increment


/******************************
 *
 * Function:	SHIFTER MODULE
 * Author:		Fred Love
 * Created:		11/16/15
 * Modified:	N/A
 *
 *******************************/
void SHIFTER::shift(void){

	shift_busy.notify();
	shift_complete.notify();
	shift_available.notify();

}//end shift


/******************************
 *
 * Function:	BOOLEAN MODULE
 * Author:		Fred Love
 * Created:		11/16/15
 * Modified:	N/A
 *
 *******************************/
void BOOLEAN::logic_operation(void){

	bool_busy.notify();
	bool_complete.notify();
	bool_available.notify();

}//end logic_operation






