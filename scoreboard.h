/*
 * scoreboard.h
 *
 *  Created on: Nov 27, 2014
 *      Author: fred
 */

#ifndef SCOREBOARD_H_
#define SCOREBOARD_H_

#include <systemc.h>
#include "register_lib.h"

SC_MODULE (SCOREBOARD){

	//ports, processes, internal data

	//Process declarations/prototypes
	void update_operand_status(void);
	void update_unit_status(void);
	void read_operand_status(void);
	void read_unit_status(void);



	//Constructor
	SC_CTOR(SCOREBOARD){



	}//end SC_CTOR

}//end SCOREBOARD




#endif /* SCOREBOARD_H_ */
