/*
 * sc_module_lib.h
 *
 *  Created on: Nov 16, 2014
 *      Author: fred
 */
#include<systemc.h>
#ifndef SC_MODULE_LIB_H_
#define SC_MODULE_LIB_H_

/******************************
 *
 * Function:	MULTIPLIER MODULE
 * Author:		Fred Love
 * Created:		11/16/15
 * Modified:	N/A
 *
 *******************************/
SC_MODULE (multiplier) {

   //ports, processes, internal data
   sc_in<int> inA;
   sc_in<int> inB;
   sc_out<int> product;

   void multiply (){
      product = inA * inB;
   }

   SC_CTOR (multiplier){
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
SC_MODULE (divider) {

   //ports, processes, internal data
   sc_in<int> inA;
   sc_in<int> inB;
   sc_out<int> quotient;

   void divide (){
      quotient = inA / inB;
   }

   SC_CTOR (divider){
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
SC_MODULE (fixed_add) {

   //ports, processes, internal data
   sc_in<int> inA;
   sc_in<int> inB;
   sc_out<int> sum;

   void add (){
      sum = inA + inB;
   }

   SC_CTOR (fixed_add){
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
SC_MODULE (floating_add) {

   //ports, processes, internal data
   sc_in<int> inA;
   sc_in<int> inB;
   sc_out<int> sum;

   void add (){

	   //How to distinguish between floating and fixed?
	   //Do operations need to be changed to bit level?
	   sum = inA + inB;
   }

   SC_CTOR (floating_add){
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
SC_MODULE (incrementer) {

   //ports, processes, internal data
   sc_in<int> in;
   sc_out<int> result;

   void increment (){

	   //How to distinguish between floating and fixed?
	   //Do operations need to be changed to bit level?
	   result = in + 1;
   }

   SC_CTOR (incrementer){
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
SC_MODULE (shifter) {

   //ports, processes, internal data
   sc_in<int> in;
   sc_in<int> num;
   sc_out<int> result;

   void shift (){

	   //How to distinguish between floating and fixed?
	   //Do operations need to be changed to bit level?
	   result = in << num;
   }

   SC_CTOR (shifter){
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
SC_MODULE (boolean) {

   //ports, processes, internal data
   sc_in<int> inA;
   sc_in<int> inB;
   sc_in<int> select;
   sc_out<int> result;

   void logic_operation (){

	   switch (select){
	   case 0:
		   result = inA & inB;
		   break;
	   case 1:
		   result = inA | inB;
		   break;
	   case 2:
		   result = !inA;

	   }
   }

   SC_CTOR (boolean){
      SC_METHOD (logic_operation);
      sensitive << in;

   } //end SC_CTOR

}; //end boolean

#endif /* SC_MODULE_LIB_H_ */
