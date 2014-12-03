
#include <systemc.h>
#include <instruction.h>

SC_MODULE(instruction_fifo_pipeline) {
	void m_issue_instruction(void);
	void m_instruction_source(void);
	//int program_selection;
	//Constructor
	SC_CTOR(instruction_fifo_pipeline) {
		SC_METHOD(m_issue_instruction);
		SC_THREAD(m_instruction_source);
		
		sc_fifo<Instruction> fifo_buffer (8);
	}
	
	sc_fifo<Instruction> fifo_buffer;
};

void instruction_fifo_pipeline::m_issue_instruction(void) {
	Instruction next_instruction;
	if( fifo_buffer.nb_read(next_instruction)) {
		cout << sc_time_stamp() << " packet: " << next_instruction << endl;
	}
	else {
		cout << sc_time_stamp() << " instruction pipeline empty" <<endl;
	}
	
	next_trigger(2, SC_NS);
}

void instruction_fifo_pipeline::m_instruction_source(void) {
	int program_selection = 0; // get from main
	Instruction next_instruction(increment, LONG, a1, a1, k);
	for(;;) {
		wait(3, SC_NS);
		//next_instruction++;
		fifo_buffer.write(next_instruction);
	}
}
	
	
