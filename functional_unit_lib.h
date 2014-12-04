/*
 * functional_unit_lib.h
 *
 *  Created on: Nov 17, 2014
 *      Author: fred
 */

#ifndef FUNCTIONAL_UNIT_LIB_H_
#define FUNCTIONAL_UNIT_LIB_H_
#define ADDREG_WIDTH 18
#define INDEXREG_WIDTH 18

#include "systemc.h"


/******************************
 *
 * Function:	MULTIPLIER MODULE
 * Author:		Fred Love
 * Created:		11/16/15
 * Modified:	N/A
 *
 *******************************/
SC_MODULE (MULTIPLIER) {

   //ports, processes, internal data
   sc_in<bool> op_ready;
   sc_out<int> cycle_delay;

    sc_in<bool> is_CDC600;
    sc_in<bool> reset_count; //new instruction issued
   	sc_out<bool> result;
	sc_out<bool> busy;

	

   //Process prototypes/declarations
   void multiply (void);
   {

   }

   SC_CTOR (MULTIPLIER){
      SC_METHOD (multiply);
      sensitive << op_ready;

   } //end SC_CTOR




}; //end multiplier


/******************************
 *
 * Function:	DIVIDER MODULE
 * Author:		Fred Love
 * Created:		11/16/15
 * Modified:	N/A
 *
 *******************************/
SC_MODULE (DIVIDER) {

	//ports, processes, internal data
	   sc_in<bool> op_ready;
	   sc_out<int> cycle_delay;

	   //Process prototypes/declarations
	   void divide (void);

	   SC_CTOR (DIVIDER){
	      SC_METHOD (divide);
	      sensitive << op_ready;


   } //end SC_CTOR

}; //end divider


/******************************
 *
 * Function:	FIXED_ADD MODULE
 * Author:		Fred Love
 * Created:		11/16/15
 * Modified:	N/A
 *
 *******************************/
SC_MODULE (FIXED_ADD) {

	//ports, processes, internal data
	   sc_in<bool> op_ready;
	   sc_out<int> cycle_delay;

	   //Process prototypes/declarations
	   void add (void);

	   SC_CTOR (FIXED_ADD){
	      SC_METHOD (add);
	      sensitive << op_ready;

   } //end SC_CTOR

}; //end fixed


/******************************
 *
 * Function:	FLOATING_ADD MODULE
 * Author:		Fred Love
 * Created:		11/16/15
 * Modified:	N/A
 *
 *******************************/
SC_MODULE (FLOATING_ADD) {

	//ports, processes, internal data
	   sc_in<bool> op_ready;
	   sc_out<int> cycle_delay;

	   //Process prototypes/declarations
	   void add (void);

	   SC_CTOR (FLOATING_ADD){
	      SC_METHOD (add);
	      sensitive << op_ready;


   } //end SC_CTOR

}; //end floating


/******************************
 *
 * Function:	INCREMENTER MODULE
 * Author:		Fred Love
 * Created:		11/16/15
 * Modified:	N/A
 *
 *******************************/
SC_MODULE (INCREMENTER) {

	//ports, processes, internal data
	   sc_in<bool> op_ready;
	   sc_out<int> cycle_delay;

	   //Process prototypes/declarations
	   void increment (void);

	   SC_CTOR (INCREMENTER){
	      SC_METHOD (increment);
	      sensitive << op_ready;

   } //end SC_CTOR

}; //end increment


/******************************
 *
 * Function:	SHIFTER MODULE
 * Author:		Fred Love
 * Created:		11/16/15
 * Modified:	N/A
 *
 *******************************/
SC_MODULE (SHIFTER) {

	//ports, processes, internal data
	   sc_in<bool> op_ready;
	   sc_out<int> cycle_delay;

	   //Process prototypes/declarations
	   void shift (void);

	   SC_CTOR (SHIFTER){
	      SC_METHOD (shift);
	      sensitive << op_ready;

   } //end SC_CTOR

}; //end shifter


/******************************
 *
 * Function:	BOOLEAN MODULE
 * Author:		Fred Love
 * Created:		11/16/15
 * Modified:	N/A
 *
 *******************************/
SC_MODULE (BOOLEAN) {

	//ports, processes, internal data
	   sc_in<bool> op_ready;
	   sc_out<int> cycle_delay;

	   //Process prototypes/declarations
	   void logic_operation (void);

	   SC_CTOR (BOOLEAN){
	      SC_METHOD (logic_operation);
	      sensitive << op_ready;


   } //end SC_CTOR

}; //end boolean

/******************************
 *
 * Function:	BRANCHER MODULE
 * Author:		Fred Love
 * Created:		11/16/15
 * Modified:	N/A
 *
 *******************************/
SC_MODULE (BRANCHER) {

	//ports, processes, internal data
	   sc_in<bool> op_ready;
	   sc_out<int> cycle_delay;

	   //Process prototypes/declarations
	   void branch (void);

	   SC_CTOR (BRANCHER){
	      SC_METHOD (branch);
	      sensitive << op_ready;


   } //end SC_CTOR

}; //end boolean



#endif /* FUNCTIONAL_UNIT_LIB_H_ */
