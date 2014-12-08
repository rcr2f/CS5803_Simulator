/*
 * instruction_buffer.cpp
 *
 *      Author: rebecca
 */
 
#include <systemc.h>
#include <instruction.h>
#include "programs.h"
#include "scoreboard.cpp"
#include "timing_table.h"

    
SC_MODULE(instruction_buffer) {
	sc_in_clk clock;
	sc_inout< bool > end; 
	sc_inout< bool > is_CDC6600;
	sc_inout< int > sig_clock_cycles;
	
	void m_issue_instruction(void);
	void m_instruction_source(void);
	
	//output for timing table
	Timing_Table * timing_table;
	SCOREBOARD * m_scoreboard;
	
	int m_program_selection;
	int instruction_addr;
	void init_timing_table() {
		m_scoreboard->timing_table = timing_table;
		m_scoreboard->init_timing_table();
	}
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
		m_scoreboard->sig_clock_cycles(sig_clock_cycles);
		//m_scoreboard->timing_table = timing_table;

		
	}
	
	sc_fifo<Instruction> fifo_buffer;
};

void instruction_buffer::m_issue_instruction(void) {
	Instruction next_instruction;
	while(true) {
		if( fifo_buffer.nb_read(next_instruction)) {
			m_scoreboard->fifo_buffer.write(next_instruction);
			//timing_table->print();
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
		if(instruction_addr<16)
			fifo_buffer.write(program3[instruction_addr]);

		if(program3[instruction_addr].m_opcode == branch && program_3_loop > 1) {
			instruction_addr += program3[instruction_addr].m_offset;
			program_3_loop-=1;
			for(int i=0; i<14; i++) {
				program3[instruction_addr+i].instr_count = program3[instruction_addr+i].instr_count + (14);
			}
		}
		else {
			instruction_addr++;
		}
		
		wait(2, SC_NS);
	}
	}
	

}
	
	
