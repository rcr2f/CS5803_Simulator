/*
 * functional_unit_lib.h
 *
 *  Created on: Nov 17, 2014
 *      Author: fred
 */

#ifndef FUNCTIONAL_UNIT_LIB_H_
#define FUNCTIONAL_UNIT_LIB_H_
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
   sc_in<int> inA;
   sc_in<int> inB;
   sc_out<int> product;

   //Events
   sc_event multiply_busy, multiply_available;
   sc_event multiply_complete;

   //Process prototypes/declarations
   void multiply (void);

   SC_CTOR (MULTIPLIER){
      SC_METHOD (multiply);
      sensitive << inA << inB;

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
   sc_in<int> inA;
   sc_in<int> inB;
   sc_out<int> quotient;

   //Events
   sc_event divide_busy, divide_available;
   sc_event divide_complete;

   //Process prototypes/declarations
   void divide (void);

   SC_CTOR (DIVIDER){
      SC_METHOD (divide);
      sensitive << inA << inB;

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
   sc_in<int> inA;
   sc_in<int> inB;
   sc_out<int> sum;

   //Process prototypes/declarations
   void add (void);

   //Events
   sc_event fixed_add_busy, fixed_add_available;
   sc_event fixed_add_complete;

   SC_CTOR (FIXED_ADD){
      SC_METHOD (add);
      sensitive << inA << inB;

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
   sc_in<int> inA;
   sc_in<int> inB;
   sc_out<int> sum;

   //Events
   sc_event float_add_busy, float_add_available;
   sc_event float_add_complete;

   //Process prototypes/declarations
   void add (void);

   SC_CTOR (FLOATING_ADD){
      SC_METHOD (add);
      sensitive << inA << inB;

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
   sc_in<int> in;
   sc_out<int> result;

   //Events
   sc_event increment_busy, increment_available;
   sc_event increment_complete;

   //Process prototypes/declarations
   void increment (void);

   SC_CTOR (INCREMENTER){
      SC_METHOD (increment);
      sensitive << in;

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
   sc_in<int> in;
   sc_in<int> num;
   sc_out<int> result;

   //Events
   sc_event shift_busy, shift_available;
   sc_event shift_complete;

   //Process prototypes/declarations
   void shift (void);

   SC_CTOR (SHIFTER){
      SC_METHOD (shift);
      sensitive << in;

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
   sc_in<int> inA;
   sc_in<int> inB;
   sc_in<int> select;
   sc_out<int> result;

   //Events
   sc_event bool_busy, bool_available;
   sc_event bool_complete;

   void logic_operation (void);


   SC_CTOR (BOOLEAN){
      SC_METHOD (logic_operation);
      sensitive << inA << inB << select;

   } //end SC_CTOR

}; //end boolean



#endif /* FUNCTIONAL_UNIT_LIB_H_ */
