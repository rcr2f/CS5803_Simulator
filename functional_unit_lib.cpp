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

	if (is_CDC6600){
		cycle_delay = 10;
	}
	else
		cycle_delay = 5;
		

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

	if (is_CDC6600){
			cycle_delay = 29;
		}
	else
		cycle_delay = 20;

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

	if (is_CDC6600){
		cycle_delay = 3;
	}
	else
		cycle_delay = 2;

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

	if (is_CDC6600){
		cycle_delay = 4;
	}
	else
		cycle_delay = 4;

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

	if (is_CDC6600){
		cycle_delay = 3;
	}
	else
		cycle_delay = 2;

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

	if (is_CDC6600){
		cycle_delay = 4;
	}
	else
		cycle_delay = 2;

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

	if (is_CDC6600){
		cycle_delay = 3;
	}
	else
		cycle_delay = 2;

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

	if (is_CDC6600){
		cycle_delay = 14;
	}
	else
		cycle_delay = 14;
		//CDC7600 has no branch unit?

}//end branch






