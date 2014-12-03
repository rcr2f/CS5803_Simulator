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
	sc_signal<bool> unitStatSig;
	sc_signal< sc_uint<4> > unitSelectSig;

	FUNC_UNIT_STATUS *unit_stat_reg;

	enum Operation {
		multiply,
		divide,
		fixed_add,
		float_add,
		boolean,
		shift,
		branch,
		increment
	};

	enum Unit {
		float_adder,
		multiplier1,
		multiplier2,
		divider,
		fixed_adder,
		incrementer1,
		incrementer2,
		bool_unit,
		shifter,
		brancher
	};



	//Process declarations/prototypes


	//FOUR STAGES OF SCOREBOARD CONTROL
	void issue_stage(void);
	void readop_stage(void);
	void execute_stage(void);
	void writebk_stage(void);


	//THREE PARTS OF SCOREBOARD
	enum Instruct_Stat {issue, readop, execute, writebk};

	struct Unit_Stat{
		bool isBusy;
		Operation op;
		sc_uint<3> dest;
		sc_uint<3> source1;
		sc_uint<3> source2;
		Unit func1;
		Unit func2;
		bool func1_ready;
		bool func2_ready;
	};

	struct Reg_Result_Stat{
		Unit r0;
		Unit r1;
		Unit r2;
		Unit r3;
		Unit r4;
		Unit r5;
		Unit r6;
		Unit r7;
	};

/*
	void update_operand_status(void);
	void update_unit_status(void);
	void read_operand_status(void);
	void read_unit_status(void);
*/

	//Helper function declarations/prototypes
	void decode_short (shortInstruct);
	void decode_long (longInstruct);


	//Constructor
	SC_CTOR(SCOREBOARD){

		SC_METHOD (issue_stage);
		//sensitivity here

		SC_METHOD (readop_stage);
		//sensitivity here

		SC_METHOD (execute_stage);
		//sensitivity here

		SC_METHOD (writebk_stage);
		//sensitivity here

		//FUNC_UNIT_STATUS unit_stat_reg ("Func Unit Status Reg");
		//GLOB_OP_STATUS op_stat_reg ("Operand Status Reg");

		//Func unit status reg instantiation and port binding
		unit_stat_reg = new FUNC_UNIT_STATUS ("Func Unit Status Reg");
		unit_stat_reg -> outStatus( unitStatSig );
		unit_stat_reg -> unitSelect( unitSelectSig );



	}//end SC_CTOR

}//end SCOREBOARD




#endif /* SCOREBOARD_H_ */
