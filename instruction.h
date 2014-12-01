#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_


class Instruction{
	public:
		int m_opcode_number;
		int m_time_to_execute;
		bool m_is_long;
	
	public:
		Instruction();
		
		void set_opcode(int opcode);
		
		int set_execution_time();

		bool set_length_of_opcode();
};

#endif /* INSTRUCTION_H_ */
