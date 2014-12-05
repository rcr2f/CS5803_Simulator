/*
 * scoreboard.h
 *
 *  Created on: Nov 27, 2014
 *      Author: fred
 */

#ifndef SCOREBOARD_H_
#define SCOREBOARD_H_

#include <systemc.h>
//#include "register_lib.h" rebecca
//rebecca
#include "functional_unit_lib.cpp"
#include "instruction.h"
#include "enums.h"

SC_MODULE (SCOREBOARD){

	//ports, processes, internal data
	//sc_signal<bool> unitStatSig; rebecca
	//sc_signal< sc_uint<4> > unitSelectSig; rebecca

	//rebecca
	sc_in_clk clock;
	sc_inout< bool > end;
	sc_fifo<Instruction> fifo_buffer;
	sc_fifo<Instruction> hazard_buffer;
	sc_inout< bool > is_CDC6600;
	
	//functional units
	MULTIPLIER * m_mult;
	DIVIDER * m_div;
	FIXED_ADD * m_fixed_add;
	FLOATING_ADD * m_floating_add;
	INCREMENTER * m_inc;
	SHIFTER * m_shift;
	BOOLEAN * m_bool;
	BRANCHER * m_branch;
	
	//sc_in<Instruction> issued_instruction;
	//sc_out<bool> ready_for_instruction;
	
	//FUNC_UNIT_STATUS *unit_stat_reg; rebecca
/*
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
	*/



	//Process declarations/prototypes
	void issue_stage(void);
	
/*rebecca

	//FOUR STAGES OF SCOREBOARD CONTROL
	
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
*/
/*
	void update_operand_status(void);
	void update_unit_status(void);
	void read_operand_status(void);
	void read_unit_status(void);
*/
	//Helper function declarations/prototypes
	bool check_unit_haz(void);
	bool check_data_haz(void);
	
//	void decode_short (shortInstruct);
	
	int count;
	void test(void)
	{
		Instruction next_instruction;
		
		if(fifo_buffer.nb_read(next_instruction)) {
			cout << sc_time_stamp() << " packet: " << next_instruction << endl;
		}
		else 
			count++;
		if (count == 5) {
			end = true;
		}

	}
	//Constructor
	SC_CTOR(SCOREBOARD){
		SC_METHOD (test);
		sensitive << clock.pos();
		
		sc_fifo<Instruction> fifo_buffer (32);
		sc_fifo<Instruction> hazard_buffer (32);
		
		//initializing functional units
		m_mult = new MULTIPLIER("Multiplier0");
		m_mult->clock(clock);
		m_mult->is_CDC6600(is_CDC6600);
		
		m_div = new DIVIDER("Divider0");
		m_div->clock(clock);;
		m_div->is_CDC6600(is_CDC6600);
		
		m_fixed_add = new FIXED_ADD("Fixed_Add0");
		m_fixed_add->clock(clock);
		m_fixed_add->is_CDC6600(is_CDC6600);
		
		m_floating_add = new FLOATING_ADD("Floating_Add0");
		m_floating_add->clock(clock);
		m_floating_add->is_CDC6600(is_CDC6600);
		
		m_inc = new INCREMENTER("Incrementer0");
		m_inc->clock(clock);
		m_inc->is_CDC6600(is_CDC6600);
		
		m_shift = new SHIFTER("Shifter0");
		m_shift->clock(clock);
		m_shift->is_CDC6600(is_CDC6600);
		
		m_bool = new BOOLEAN("Boolean0");
		m_bool->clock(clock);
		m_bool->is_CDC6600(is_CDC6600);
		
		m_branch = new BRANCHER("Brancher0");
		m_branch->clock(clock);
		m_branch->is_CDC6600(is_CDC6600);
		
/*rebecca
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

*/
		count = 0;
	}//end SC_CTOR

};//end SCOREBOARD




#endif /* SCOREBOARD_H_ */
