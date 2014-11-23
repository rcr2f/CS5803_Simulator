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
#define INDEXREG_WIDTH 18
#define HOPREG_WIDTH 18

#include <systemc.h>


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
	sc_uint<3> F;
	sc_uint<3> m;
	sc_uint<3> i;
	sc_uint<3> j;
	sc_uint<3> k;
};

struct longInstruct {
	//F+m = opcode
	//i,j= refer to one of A, X, B registers
	//k = immediate value for const or branching
	sc_uint<3> F;
	sc_uint<3> m;
	sc_uint<3> i;
	sc_uint<3> j;
	sc_uint<18> k;
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
	sc_uint<OPREG_WIDTH> opReg[8];

	//Process declarations/prototypes
   void read_data (void);
   void write_data (void);

	//Constructor
	SC_CTOR (GLOB_OP_REGS){
		SC_METHOD(read_data);
		sensitive << regSelect;

		SC_METHOD(write_data);
		sensitive << regSelect;
	}//end SC_CTOR

}; //end GLOB_OP_REGS


/************************************************
 *
 * Function:	ADDRESS REGISTER
 * Author:		Fred Love
 * Created:		11/19/15
 * Modified:	N/A
 *
 ***********************************************/
SC_MODULE (ADDRESS_REGS){

	//ports, processes, internal data
	sc_in< sc_uint<3> > regSelect;
	sc_in< sc_uint<ADDREG_WIDTH> > dataIn;
	sc_out< sc_uint<ADDREG_WIDTH> > dataOut;
	sc_uint<ADDREG_WIDTH> addReg[8];

	void read_data (void);
   void write_data (void);

	//Constructor
	SC_CTOR (ADDRESS_REGS){
		SC_METHOD(read_data);
		sensitive << regSelect;

		SC_METHOD(write_data);
		sensitive << regSelect;
	}//end SC_CTOR

}; //end ADDRESS_REGS


/************************************************
 *
 * Function:	INDEX REGISTERS
 * Author:		Fred Love
 * Created:		11/19/15
 * Modified:	N/A
 *
 ***********************************************/
SC_MODULE (INDEX_REGS){

	//ports, processes, internal data
	sc_in< sc_uint<3> > regSelect;
	sc_in< sc_uint<INDEXREG_WIDTH> > dataIn;
	sc_out< sc_uint<INDEXREG_WIDTH> > dataOut;
	sc_uint<INDEXREG_WIDTH> indexReg[8];

	//Process prototypes/declarations
   void read_data (void);
   void write_data (void);

	//Constructor
	SC_CTOR (INDEX_REGS){
		SC_METHOD(read_data);
		sensitive << regSelect;

		SC_METHOD(write_data)
		sensitive << regSelect;
	}//end SC_CTOR

}; //end INDEX_REGS

/************************************************
 *
 * Function:	FUNCTIONAL OPERAND REGISTERS
 * Author:		Fred Love
 * Created:		11/19/15
 * Modified:	N/A
 *
 ***********************************************/
SC_MODULE (FUNC_OP_REGS){

	//ports, processes, internal data
	sc_in< sc_uint<4> > regSelect;
	sc_in< sc_uint<OPREG_WIDTH> > dataIn;
	sc_out< sc_uint<OPREG_WIDTH> > dataOut;
	sc_uint<OPREG_WIDTH> opReg[10];

	//Process prototypes/declarations
   void read_data(void);
   void write_data(void);

	//Constructor
	SC_CTOR (FUNC_OP_REGS){
		SC_METHOD(read_data);
		sensitive << regSelect;

		SC_METHOD(write_data)
		sensitive << regSelect;
	}//end SC_CTOR

}; //end FUNC_OP_REGS


/************************************************
 *
 * Function:	STUNT BOX HOPPERS
 * Author:		Fred Love
 * Created:		11/19/15
 * Modified:	N/A
 *
 ***********************************************/
SC_MODULE (HOPPER_REGS){

	//ports, processes, internal data
	sc_in< sc_uint<2> > regSelect;
	sc_in< sc_uint<HOPREG_WIDTH> > dataIn;
	sc_out< sc_uint<HOPREG_WIDTH> > dataOut;
	sc_uint<HOPREG_WIDTH> hopReg[4];

	//Process prototypes/declarations
   void read_data(void);
   void write_data(void);

	//Constructor
	SC_CTOR (HOPPER_REGS){
		SC_METHOD(read_data);
		sensitive << regSelect;

		SC_METHOD(write_data)
		sensitive << regSelect;
	}//end SC_CTOR

}; //end HOPPER_REGS

/************************************************
 *
 * Function:	FUNCTIONAL UNIT STATUS REGISTER
 * Author:		Fred Love
 * Created:		11/19/15
 * Modified:	N/A
 *
 ***********************************************/

struct STATUS_REG {
	sc_bit float_adder_stat;
	sc_bit multiply_one_stat;
	sc_bit multiply_two_stat;
	sc_bit divide_stat;
	sc_bit fixed_add_stat;
	sc_bit increment_one_stat;
	sc_bit increment_two_stat;
	sc_bit boolean_stat;
	sc_bit shifter_stat;
	sc_bit branch_stat;
};


#endif /* REGISTER_LIB_H_ */
