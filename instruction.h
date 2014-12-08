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

#include "enums.h"
#include <iostream>
#include <fstream>
using namespace std;


	
class Instruction{
	public:
		_register m_destination, m_source1, m_source2;
		Operation m_opcode;
		opcode_length m_length;
		int m_offset;
		//output file info
		int instr_count;
		ostream * outFile;

	public:
		Instruction();
		
		Instruction(Operation opcode, opcode_length length, _register dest, _register src1,  _register src2, int instr_row);
		
		//special constructor needed for branch
		Instruction(Operation opcode, opcode_length length, int offset, int instr_row);
		
		friend ostream& operator<<(ostream& os, const Instruction& instr);

};

#endif /* INSTRUCTION_H_ */
