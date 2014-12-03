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
#define NUM_OP_REGS 8
#define NUM_FUNC_UNITS 10

#include <systemc.h>
#include "functional_unit_lib.h"

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
	//sc_in< sc_uint<OPREG_WIDTH> > dataIn;
	//sc_out< sc_uint<OPREG_WIDTH> > dataOut;
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

/*
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
*/

SC_MODULE (FUNC_UNIT_STATUS){

	//ports, processes, internal data
	sc_in< sc_uint<4> > unitSelect;
	sc_in<bool> inRequest, statusCheck;
	sc_out<bool> outStatus;
	bool statusReg[10];


	//Process prototypes/declarations
	void add_request (void);
	void output_status (void);

	//Helper function prototypes/declarations
	void make_available (sc_uint<4> );

	SC_CTOR(FUNC_UNIT_STATUS){
		SC_METHOD(add_request);
		sensitive << inRequest << unitSelect;

		SC_METHOD(output_status);
		sensitive << statusCheck << unitSelect;


	}//end SC_CTOR

};//end STATUS_REG

/************************************************
 *
 * Function:	GLOBAL OPERAND STATUS
 * Author:		Fred Love
 * Created:		11/19/15
 * Modified:	N/A
 * Comments:    Holds the read/write count of
 *              each global operand register.
 *              1.) If operand is not being read from or
 *                  written to its available for write requests.
 *              2.) Multiple read requests can occur. Only one write
 *              3.) This module handles updating the status.  The
 *                  scoreboard will enforce the policies.
 *
 ***********************************************/
SC_MODULE (GLOB_OP_STATUS){

	//ports, processes, internal data
	struct status_node{
		int read_count;
		int write_count;
		bool read_available;
		bool write_available;
	};

	sc_in< sc_uint<3> > regSelect;
	sc_out<int> readCountOut, writeCountOut;
	sc_out<bool> readAvailableOut, writeAvailableOut;
	status_node statusReg[NUM_OP_REGS];

	//Process declarations/prototypes
   void check_read (void);   //outputs op reg read count
   void check_write (void);  //outputs op reg write count
   void request_read(void);  //increment op reg read request
   void request_write(void); //increment op reg write request
   void read_available(void); //used to broadcast if op reg is free for read
   void write_available(void); //used to broadcast if op reg is free for write

   //Helper function declarations/prototypes
   void decrement_read(status_node &);
   void decrement_write(status_node &);
   //notify function may not be needed.  When time/count gets to zero just decement
   //bool notifyOpComplete(void);

	//Constructor
	SC_CTOR (GLOB_OP_STATUS){
		//SC_METHOD(read_data);
		//sensitive << regSelect;

		//SC_METHOD(write_data);
		//sensitive << regSelect;
	}//end SC_CTOR

}; //end GLOB_OP_REGS

#endif /* REGISTER_LIB_H_ */
