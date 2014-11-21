/*
 * register_lib.h
 *
 *  Created on: Nov 19, 2014
 *      Author: fred
 */

#ifndef REGISTER_LIB_H_
#define REGISTER_LIB_H_
#define OPREG_WIDTH 60
#define ADDREG_WIDTH 18
#define INDREG_WIDTH 18
#include "systemc.h"

/************************************************
 *
 * Function:	SHORT/LONG INSTRUCTION REGISTER
 * Author:		Fred Love
 * Created:		11/19/15
 * Modified:	N/A
 *
 ***********************************************/

struct shortInstruct {
	//F+m = opcode
	//i,j,k = refer to one of A, X, B registers
	bool F[3];
	bool m[3];
	bool i[3];
	bool j[3];
	bool k[3];
};

struct longInstruct {
	//F+m = opcode
	//i,j= refer to one of A, X, B registers
	//k = immediate value for const or branching
	bool F[3];
	bool m[3];
	bool i[3];
	bool j[3];
	bool k[18];
};


/************************************************
 *
 * Function:	GLOBAL OPERAND REGISTERS
 * Author:		Fred Love
 * Created:		11/19/15
 * Modified:	N/A
 *
 ***********************************************/
SC_MODULE (GLOB_OP_REGS){

	//ports, processes, internal data
	sc_in< sc_uint<3> > regSelect;
	sc_in< sc_uint<OPREG_WIDTH> > dataIn;
	sc_out< sc_uint<OPREG_WIDTH> > dataOut;

	//Constructor
	SC_CTOR (GLOB_OP_REGS){

	}//end SC_CTOR

}; //end GLOB_OP_REGS


#endif /* REGISTER_LIB_H_ */
