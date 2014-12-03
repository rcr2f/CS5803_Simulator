/*
 * file: instruction.h
 * project: CDC6600/CDC7600
 * 
 *  Created on: Dec 1, 2014
 *      Author:  rebecca
 * 
 * description: instruction class used to descibe the instructions 
 * 		needed to run the CDC6600/CDC7600 simulator				 
 */

#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include <iostream>
using namespace std;

enum _register {
	x0,
    x1,
    x2,
    x3,
    x4,
    x5,
    x6,
    x7,
    a0,
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    b0,
    b1,
    b2,
    b3,
    b4,
    b5,
    b6,
    b7,
    k
 };
        
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
		
enum opcode_length {
	SHORT,
    LONG
};
	
class Instruction{
	public:
		_register m_destination, m_source1, m_source2;
		Operation m_opcode;
		opcode_length m_length;
		int m_time_to_execute;

	public:
		Instruction();
		
		Instruction(Operation opcode, opcode_length length, _register dest,  _register src1,  _register src2);
		
		friend ostream& operator<<(ostream& os, const Instruction& instr);
		/*
		void set_opcode(int opcode);
		
		int set_execution_time();

		bool set_length_of_opcode();*/
};

#endif /* INSTRUCTION_H_ */
