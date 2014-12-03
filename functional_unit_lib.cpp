/*
 * functional_unit_lib.cpp
 *
 *  Created on: Nov 22, 2014
 *      Author: fred
 */

#include <systemc.h>
#include "functional_unit_lib.h"
//#include "register_lib.h"

/******************************
 *
 * Function:	MULTIPLIER MODULE
 * Author:		Fred Love
 * Created:		11/16/15
 * Modified:	N/A
 *
 *******************************/
void MULTIPLIER::multiply(void){

	if (op_ready){
		cycle_delay.write(10);
	}

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

	if (op_ready){
			cycle_delay.write(29);
		}

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

	if (op_ready){
		cycle_delay.write(3);
	}

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

	if (op_ready){
		cycle_delay.write(4);
	}

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

	if (op_ready){
		cycle_delay.write(3);
	}

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

	if (op_ready){
		cycle_delay.write(4);
	}

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

	if (op_ready){
		cycle_delay.write(3);
	}

}//end logic_operation

/******************************
 *
 * Function:	BRANCHER MODULE
 * Author:		Fred Love
 * Created:		11/16/15
 * Modified:	N/A
 *
 *******************************/
void BRANCHER::branch(void){

	if (op_ready){
		cycle_delay.write(14);
	}

}//end branch






