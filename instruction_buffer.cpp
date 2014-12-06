/*
 * instruction_buffer.cpp
 *
 *      Author: rebecca
 */
 
#include <systemc.h>
#include <instruction.h>
#include "programs.h"
#include "scoreboard.cpp"

    
SC_MODULE(instruction_buffer) {
	sc_in_clk clock;
	sc_inout< bool > end; 
	sc_inout< bool > is_CDC6600;
	
	void m_issue_instruction(void);
	void m_instruction_source(void);
	
	SCOREBOARD * m_scoreboard;
	
	int m_program_selection;
	int instruction_addr;

	//Constructor
	SC_CTOR(instruction_buffer) {
		
		SC_THREAD(m_issue_instruction);

		SC_THREAD(m_instruction_source);

		
		sc_fifo<Instruction> fifo_buffer (16);
		instruction_addr =0;
		
		m_scoreboard = new SCOREBOARD("scoreboard0");
		m_scoreboard->clock(clock);
		m_scoreboard->end(end);
		m_scoreboard->is_CDC6600(is_CDC6600);
		
	}
	
	sc_fifo<Instruction> fifo_buffer;
};

void instruction_buffer::m_issue_instruction(void) {
	Instruction next_instruction;
	while(true) {
		if( fifo_buffer.nb_read(next_instruction)) {
			m_scoreboard->fifo_buffer.write(next_instruction);
		}
		wait(2, SC_NS);
	}


}

void instruction_buffer::m_instruction_source(void) {
	while(true) {
	if(instruction_addr >= size[m_program_selection]) {
		wait(2, SC_NS);
		return;
	}
	else if(1 == m_program_selection) {
		fifo_buffer.write(program1[instruction_addr]);
		instruction_addr++;
		
		wait(1, SC_NS);
	}
	else if(2 == m_program_selection) {
		fifo_buffer.write(program2[instruction_addr]);
		instruction_addr++;
		
		wait(1, SC_NS);
	}
	else if(3 == m_program_selection){
		fifo_buffer.write(program3[instruction_addr]);

		if(program3[instruction_addr].m_opcode == branch && program_3_loop > 0) {
			instruction_addr += program3[instruction_addr].m_offset;
			program_3_loop-=1;
		}
		else {
			instruction_addr++;
		}
		
		wait(2, SC_NS);
	}
	}
	

}
	
	
