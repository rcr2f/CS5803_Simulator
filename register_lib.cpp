/*
 * register_lib.cpp
 *
 *  Created on: Nov 19, 2014
 *      Author: fred
 */

#include <systemc.h>
#include "register_lib.h"
#include <iomanip>



/************************************************
 *
 * Function:	GLOBAL OPERAND REGISTERS
 * Author:		Fred Love
 * Created:		11/19/15
 * Modified:	N/A
 *
 ***********************************************/

	void GLOB_OP_REGS::read_data(void){
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

	void GLOB_OP_REGS::write_data(void){
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


/************************************************
 *
 * Function:	ADDRESS REGISTER
 * Author:		Fred Love
 * Created:		11/19/15
 * Modified:	N/A
 *
 ***********************************************/
	void ADDRESS_REGS::read_data(void){
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

	void ADDRESS_REGS::write_data(void){
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


/************************************************
 *
 * Function:	INDEX REGISTERS
 * Author:		Fred Love
 * Created:		11/19/15
 * Modified:	N/A
 *
 ***********************************************/
	void INDEX_REGS::read_data(void){
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

	void INDEX_REGS::write_data(void){
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

/************************************************
 *
 * Function:	FUNCTIONAL OPERAND REGISTERS
 * Author:		Fred Love
 * Created:		11/19/15
 * Modified:	N/A
 *
 ***********************************************/
	void FUNC_OP_REGS::read_data(void){
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
			std::cout << "ERROR: Inaccessible memory access request";
			exit (1);

		}//end switch
	}// end read_data

	void FUNC_OP_REGS::write_data(){
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
				std::cout << "ERROR: Inaccessible memory access request";
				exit (1);

			}//end switch
		}// end write_data

	/************************************************
 *
 * Function:	STUNT BOX HOPPERS
 * Author:		Fred Love
 * Created:		11/19/15
 * Modified:	N/A
 *
 ***********************************************/
	void HOPPER_REGS::read_data(void){
		//regSelect.read()
		switch (regSelect.read()){
		case 0:
			hopReg[0] = dataIn;
			break;

		case 1:
			hopReg[1] = dataIn;
			break;

		case 2:
			hopReg[2] = dataIn;
			break;

		case 3:
			hopReg[3] = dataIn;
			break;

		}//end switch
	}// end read_data

	void HOPPER_REGS::write_data(void){
			//regSelect.read()
			switch (regSelect.read()){
			case 0:
				dataOut.write(hopReg[0]);
				break;

			case 1:
				dataOut.write(hopReg[1]);
				break;

			case 2:
				dataOut.write(hopReg[2]);
				break;

			case 3:
				dataOut.write(hopReg[3]);
				break;

			}//end switch
		}// end write_data


