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
	void FUNC_UNIT_STATUS::initialize_units(void){
		Unit func_unit = float_adder;
		for(int i=0; i<num_units; i++) {
			m_statusReg[i].func_unit=(Unit)(func_unit+i);
			m_statusReg[i].dest_reg = k;
			m_statusReg[i].time_until_complete=0;
			m_statusReg[i].time_until_free=0;
		}
			
	}
 
	void FUNC_UNIT_STATUS::add_request(void){
		m_statusReg[(int)func_unit].time_until_free = time_until_free;
		m_statusReg[(int)func_unit].time_until_complete = time_until_complete;
		m_statusReg[(int)func_unit].dest_reg = dest_reg;
		if(m_statusReg[(int)func_unit].time_until_free != 0) {
			m_statusReg[(int)func_unit].busy = true;
		}
	}//end add_request

	void FUNC_UNIT_STATUS::output_status(void){
		//sc_uint<4> index = unitSelect.read();
		//outStatus.write(statusReg[index]);
	}//end output_status
	
	void FUNC_UNIT_STATUS::update_status_table(void) {
		bool simulation_complete = true; 
		for(int i=0; i<num_units; i++) {
			if(m_statusReg[i].time_until_free > 0) {
				m_statusReg[i].time_until_free--;
				if(m_statusReg[i].time_until_free == 0) {
					m_statusReg[i].busy = false;
				}
				else {		
					m_statusReg[i].busy = true;
				}
			}
			if(m_statusReg[i].time_until_complete > 0) {
				m_statusReg[i].time_until_complete--;
			}
			if(m_statusReg[i].time_until_complete != 0) {
				simulation_complete = false; //There might be a case (like after a branch) where this returns true, but there are still more instructions
			}
			else
				m_statusReg[i].dest_reg = k;

		}

		//if(simulation_complete and )
		//	count++;
		if(simulation_complete and instructions_done) {
			cout<<"SHUTTING DOWN THE SIMULATOR"<<endl;
			cout<<"SHUTTING DOWN THE SIMULATOR"<<endl;
			end = simulation_complete;
		}
		else {
			end = false;
		}

	}

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
		statusReg[index].write_available = 1;
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

