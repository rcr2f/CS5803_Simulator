/*
 * functional_unit_lib.h
 *
 *  Created on: Nov 17, 2014
 *      Author: fred
 *              rebecca
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
   sc_in_clk clock;   
   sc_in<bool> is_CDC6600;
   
   //time to complete execution
   int cycle_delay;
   int time_until_free;
   
   //Process prototypes/declarations
   void multiply (void);


   SC_CTOR (MULTIPLIER){
      SC_THREAD (multiply);
      sensitive << is_CDC6600;
      
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
   sc_in_clk clock;   
   sc_in<bool> is_CDC6600;
   
   //time to complete execution
   int cycle_delay;
   int time_until_free;
   
   //Process prototypes/declarations
   void divide (void);

   SC_CTOR (DIVIDER){
      SC_THREAD (divide);
      sensitive << is_CDC6600;

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
   sc_in_clk clock;   
   sc_in<bool> is_CDC6600;
   
   //time to complete execution
   int cycle_delay;
   int time_until_free;
   
   //Process prototypes/declarations
   void add (void);

   SC_CTOR (FIXED_ADD){
      SC_THREAD (add);
      sensitive << is_CDC6600;
      
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
   sc_in_clk clock;   
   sc_in<bool> is_CDC6600;
   
   //time to complete execution
   int cycle_delay;
   int time_until_free;
   
   //Process prototypes/declarations
   void add (void);

   SC_CTOR (FLOATING_ADD){
      SC_THREAD (add);
      sensitive << is_CDC6600;

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
   sc_in_clk clock;   
   sc_in<bool> is_CDC6600;
   
   //time to complete execution
   int cycle_delay;
   int time_until_free;
   
   //Process prototypes/declarations
   void increment (void);

   SC_CTOR (INCREMENTER){
      SC_THREAD (increment);
      sensitive << is_CDC6600;

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
   sc_in_clk clock;   
   sc_in<bool> is_CDC6600;
   
   //time to complete execution
   int cycle_delay;
   int time_until_free;
   
   //Process prototypes/declarations
   void shift (void);

   SC_CTOR (SHIFTER){
      SC_THREAD (shift);
      sensitive << is_CDC6600;

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
   sc_in_clk clock;   
   sc_in<bool> is_CDC6600;
   
   //time to complete execution
   int cycle_delay;
   int time_until_free;
   
   //Process prototypes/declarations
   void logic_operation (void);

   SC_CTOR (BOOLEAN){
      SC_THREAD (logic_operation);
      sensitive << is_CDC6600;

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
   sc_in_clk clock;   
   sc_in<bool> is_CDC6600;
   
   //time to complete execution
   int cycle_delay;
   int time_until_free;
   
   //Process prototypes/declarations
   void branch (void);

   SC_CTOR (BRANCHER){
      SC_THREAD (branch);
      sensitive << is_CDC6600;

   } //end SC_CTOR

}; //end boolean



#endif /* FUNCTIONAL_UNIT_LIB_H_ */
