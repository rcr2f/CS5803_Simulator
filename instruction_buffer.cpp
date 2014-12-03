/*
 * instruction_fifo_pipeline.cpp
 *
 *      Author: rebecca
 */
 
#include <systemc.h>
#include <instruction.h>
#include "programs.h"
#include "scoreboard.cpp"

    
SC_MODULE(instruction_fifo_pipeline) {
	sc_in_clk clock;
	sc_out< bool > end; 
	void m_issue_instruction(void);
	void m_instruction_source(void);
	
	SCOREBOARD * m_scoreboard;
	
	int m_program_selection;
	int instruction_addr;
	//Constructor
	SC_CTOR(instruction_fifo_pipeline) {
		SC_METHOD(m_issue_instruction);
		sensitive << clock.pos();
		SC_METHOD(m_instruction_source);

		sc_fifo<Instruction> fifo_buffer (8);
		instruction_addr =0;
		
		m_scoreboard = new SCOREBOARD("scoreboard0");
		m_scoreboard->clock(clock);
		
	}
	
	sc_fifo<Instruction> fifo_buffer;
};

void instruction_fifo_pipeline::m_issue_instruction(void) {
	Instruction next_instruction;
	if( fifo_buffer.nb_read(next_instruction)) {
		//TODO: Send to Scoreboard
		cout << sc_time_stamp() << " packet: " << next_instruction << endl;
	}
	else if(instruction_addr == size[m_program_selection]) {
		//TODO: End at final instruction execution, not here
		cout << sc_time_stamp() << " simulation complete" <<endl;
		end.write(true);
	}
	else {
		cout << sc_time_stamp() << " instruction pipeline empty" <<endl;		
	}

}

void instruction_fifo_pipeline::m_instruction_source(void) {
	if(instruction_addr >= size[m_program_selection])
		//fifo_buffer.write(Instruction());
		return;
	else if(1 == m_program_selection) {
		fifo_buffer.write(program1[instruction_addr]);

		instruction_addr++;
	}
	else if(2 == m_program_selection) {
		fifo_buffer.write(program2[instruction_addr]);

		instruction_addr++;
	}
	next_trigger(1, SC_NS);
}
	
	