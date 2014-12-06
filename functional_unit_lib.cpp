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
		time_until_free = 10;
	}
	else {
		cycle_delay = 5;
		time_until_free = 2;
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

	if (is_CDC6600){
			cycle_delay = 29;
			time_until_free = 29;
		}
	else {
		cycle_delay = 20;
		time_until_free = 20;
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

	if (is_CDC6600){
		cycle_delay = 3;
		time_until_free = 3;
	}
	else {
		cycle_delay = 2;
		time_until_free = 1;
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

	if (is_CDC6600){
		cycle_delay = 4;
		time_until_free = 4;
	}
	else {000
		cycle_delay = 4;
		time_until_free = 1;
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

	if (is_CDC6600){
		cycle_delay = 3;
		time_until_free = 3;
	}
	else {
		cycle_delay = 2;
		time_until_free = 1;
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

	if (is_CDC6600){
		cycle_delay = 4;
		time_until_free = 4;
	}
	else {
		cycle_delay = 2;
		time_until_free = 1;
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

	if (is_CDC6600){
		cycle_delay = 3;
		time_until_free = 3;
	}
	else {
		cycle_delay = 2;
		time_until_free = 1;
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

	if (is_CDC6600){
		cycle_delay = 14;
		time_until_free = 14;
	}
	else {
		cycle_delay = 14;
		time_until_free = 14;
	}

}//end branch






