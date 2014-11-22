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
//#define STATREG_WIDTH 10
#include "systemc.h"
#include <iomanip>

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

	void read_data(){
		//regSelect.read()
		switch (regSelect.read()){
		case 0:
			opReg[0] = dataIn;
			break;

		case 1:
			opReg[1] = dataIn;
			break;

		case 2:
			opReg[2] = dataIn;
			break;

		case 3:
			opReg[3] = dataIn;
			break;

		case 4:
			opReg[4] = dataIn;
			break;

		case 5:
			opReg[5] = dataIn;
			break;

		case 6:
			opReg[6] = dataIn;
			break;

		case 7:
			opReg[7] = dataIn;
			break;

		}//end switch
	}// end read_data

	void write_data(){
			//regSelect.read()
			switch (regSelect.read()){
			case 0:
				dataOut.write(opReg[0]);
				break;

			case 1:
				dataOut.write(opReg[1]);
				break;

			case 2:
				dataOut.write(opReg[2]);
				break;

			case 3:
				dataOut.write(opReg[3]);
				break;

			case 4:
				dataOut.write(opReg[4]);
				break;

			case 5:
				dataOut.write(opReg[5]);
				break;

			case 6:
				dataOut.write(opReg[6]);
				break;

			case 7:
				dataOut.write(opReg[7]);
				break;

			}//end switch
		}// end write_data

	//Constructor
	SC_CTOR (GLOB_OP_REGS){
		SC_METHOD(read_data);
		sensitive << regSelect;

		SC_METHOD(write_data)
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

	void read_data(){
		//regSelect.read()
		switch (regSelect.read()){
		case 0:
			addReg[0] = dataIn;
			break;

		case 1:
			addReg[1] = dataIn;
			break;

		case 2:
			addReg[2] = dataIn;
			break;

		case 3:
			addReg[3] = dataIn;
			break;

		case 4:
			addReg[4] = dataIn;
			break;

		case 5:
			addReg[5] = dataIn;
			break;

		case 6:
			addReg[6] = dataIn;
			break;

		case 7:
			addReg[7] = dataIn;
			break;

		}//end switch
	}// end read_data

	void write_data(){
			//regSelect.read()
			switch (regSelect.read()){
			case 0:
				dataOut.write(addReg[0]);
				break;

			case 1:
				dataOut.write(addReg[1]);
				break;

			case 2:
				dataOut.write(addReg[2]);
				break;

			case 3:
				dataOut.write(addReg[3]);
				break;

			case 4:
				dataOut.write(addReg[4]);
				break;

			case 5:
				dataOut.write(addReg[5]);
				break;

			case 6:
				dataOut.write(addReg[6]);
				break;

			case 7:
				dataOut.write(addReg[7]);
				break;

			}//end switch
		}// end write_data

	//Constructor
	SC_CTOR (ADDRESS_REGS){
		SC_METHOD(read_data);
		sensitive << regSelect;

		SC_METHOD(write_data)
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

	void read_data(){
		//regSelect.read()
		switch (regSelect.read()){
		case 0:
			indexReg[0] = dataIn;
			break;

		case 1:
			indexReg[1] = dataIn;
			break;

		case 2:
			indexReg[2] = dataIn;
			break;

		case 3:
			indexReg[3] = dataIn;
			break;

		case 4:
			indexReg[4] = dataIn;
			break;

		case 5:
			indexReg[5] = dataIn;
			break;

		case 6:
			indexReg[6] = dataIn;
			break;

		case 7:
			indexReg[7] = dataIn;
			break;

		}//end switch
	}// end read_data

	void write_data(){
			//regSelect.read()
			switch (regSelect.read()){
			case 0:
				dataOut.write(indexReg[0]);
				break;

			case 1:
				dataOut.write(indexReg[1]);
				break;

			case 2:
				dataOut.write(indexReg[2]);
				break;

			case 3:
				dataOut.write(indexReg[3]);
				break;

			case 4:
				dataOut.write(indexReg[4]);
				break;

			case 5:
				dataOut.write(indexReg[5]);
				break;

			case 6:
				dataOut.write(indexReg[6]);
				break;

			case 7:
				dataOut.write(indexReg[7]);
				break;

			}//end switch
		}// end write_data

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
 * Function:	GLOBAL OPERAND REGISTERS
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

	void read_data(){
		//regSelect.read()
		switch (regSelect.read()){
		case 0:
			opReg[0] = dataIn;
			break;

		case 1:
			opReg[1] = dataIn;
			break;

		case 2:
			opReg[2] = dataIn;
			break;

		case 3:
			opReg[3] = dataIn;
			break;

		case 4:
			opReg[4] = dataIn;
			break;

		case 5:
			opReg[5] = dataIn;
			break;

		case 6:
			opReg[6] = dataIn;
			break;

		case 7:
			opReg[7] = dataIn;
			break;

		case 8:
			opReg[8] = dataIn;
			break;

		case 9:
			opReg[9] = dataIn;
			break;

		default:
			cout << "ERROR: Inaccessible memory access request";
			exit (1);

		}//end switch
	}// end read_data

	void write_data(){
			//regSelect.read()
			switch (regSelect.read()){
			case 0:
				dataOut.write(opReg[0]);
				break;

			case 1:
				dataOut.write(opReg[1]);
				break;

			case 2:
				dataOut.write(opReg[2]);
				break;

			case 3:
				dataOut.write(opReg[3]);
				break;

			case 4:
				dataOut.write(opReg[4]);
				break;

			case 5:
				dataOut.write(opReg[5]);
				break;

			case 6:
				dataOut.write(opReg[6]);
				break;

			case 7:
				dataOut.write(opReg[7]);
				break;

			case 8:
				dataOut.write(opReg[8]);
				break;

			case 9:
				dataOut.write(opReg[9]);
				break;

			default:
				cout << "ERROR: Inaccessible memory access request";
				exit (1);

			}//end switch
		}// end write_data

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
