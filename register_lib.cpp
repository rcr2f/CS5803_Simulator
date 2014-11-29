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
		sc_uint<3> index = regSelect.read();
		opReg[index] = dataIn;

	}//end read_data

	void GLOB_OP_REGS::write_data(void){
			sc_uint<3> index = regSelect.read();
			dataOut.write(opReg[index]);

		}//end write_data




/************************************************
 *
 * Function:	ADDRESS REGISTER
 * Author:		Fred Love
 * Created:		11/19/15
 * Modified:	N/A
 *
 ***********************************************/

	void ADDRESS_REGS::read_data(void){
		sc_uint<3> index = regSelect.read();
		addReg[index] = dataIn;
	}//end read_data

	void ADDRESS_REGS::write_data(void){
				sc_uint<3> index = regSelect.read();
				dataOut.write(addReg[index]);

	}//end write_data


/************************************************
 *
 * Function:	INDEX REGISTERS
 * Author:		Fred Love
 * Created:		11/19/15
 * Modified:	N/A
 *
 ***********************************************/

	void INDEX_REGS::read_data(void){
			sc_uint<3> index = regSelect.read();
			indexReg[index] = dataIn;
		}//end read_data

	void INDEX_REGS::write_data(void){
					sc_uint<3> index = regSelect.read();
					dataOut.write(indexReg[index]);

		}//end write_data


/************************************************
 *
 * Function:	FUNCTIONAL OPERAND REGISTERS
 * Author:		Fred Love
 * Created:		11/19/15
 * Modified:	N/A
 *
 ***********************************************/

	void FUNC_OP_REGS::read_data(void){
				sc_uint<4> index = regSelect.read();
				opReg[index] = dataIn;
			}//end read_data

	void FUNC_OP_REGS::write_data(void){
				sc_uint<4> index = regSelect.read();
				dataOut.write(opReg[index]);

			}//end write_data


	/************************************************
 *
 * Function:	STUNT BOX HOPPERS
 * Author:		Fred Love
 * Created:		11/19/15
 * Modified:	N/A
 *
 ***********************************************/
	void HOPPER_REGS::read_data(void){
					sc_uint<2> index = regSelect.read();
					hopReg[index] = dataIn;
				}//end read_data

	void HOPPER_REGS::write_data(void){
					sc_uint<2> index = regSelect.read();
					dataOut.write(hopReg[index]);

				}//end write_data



/************************************************
 *
 * Function:	FUNCTIONAL UNIT STATUS
 * Author:		Fred Love
 * Created:		11/19/15
 * Modified:	N/A
 *
 ***********************************************/
	void FUNC_UNIT_STATUS::add_request(void){
		sc_uint<4> index = unitSelect.read();
		if (statusReg[index]){
			std::cout << "Unit Busy \n";
			//exit (1)
		}
		else
			statusReg[index] = 1;
	}//end add_request

	void FUNC_UNIT_STATUS::output_status(void){
		sc_uint<4> index = unitSelect.read();
		outStatus.write(statusReg[index]);
	}//end output_status

/************************************************
 *
 * Function:	GLOBAL OPERAND STATUS
 * Author:		Fred Love
 * Created:		11/19/15
 * Modified:	N/A
 *
 ***********************************************/

	void GLOB_OP_STATUS::check_read(void){
		sc_uint<3> index = regSelect.read();
		readCountOut.write(statusReg[index].read_count);

	} //end check_read

	void GLOB_OP_STATUS::check_write(void){
		sc_uint<3> index = regSelect.read();
		readCountOut.write(statusReg[index].write_count);
	} //end check_write

	void GLOB_OP_STATUS::request_read(void){
		sc_uint<3> index = regSelect.read();
		statusReg[index].read_count = statusReg[index].read_count + 1;

	} //end request_read

	void GLOB_OP_STATUS::request_write(void){
			sc_uint<3> index = regSelect.read();
			statusReg[index].write_count = statusReg[index].write_count + 1;

		} //end request_write

	void GLOB_OP_STATUS::read_available(void){
		sc_uint<3> index = regSelect.read();
		statusReg[index].read_available = 1;

	}//end read_available

	void GLOB_OP_STATUS::write_available(void){
		sc_uint<3> index = regSelect.read();
		statusReg[index] = write_available = 1;
	}//end write_available

	/*
	bool GLOB_OP_STATUS::notifyOpComplete(void){

	}//end notifyOpComplete
	*/

	void GLOB_OP_STATUS::decrement_read(status_node &inNode){
		inNode.read_count = inNode.read_count - 1;
	}//end decementCount

	void GLOB_OP_STATUS::decrement_write(status_node &inNode){
			inNode.write_count = inNode.write_count - 1;
			if (inNode.write_count == 0){
				inNode.write_available = 1;
			}
		}//end decementCount

