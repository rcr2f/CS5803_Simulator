/*
 * file: instruction.cpp
 * project: CDC6600/CDC7600
 * 
 *  Created on: Dec 1, 2014
 *      Author:  rebecca
 * 
 * description: function definitions for Instruction class
 * 				 
 */
 
#include "instruction.h"


Instruction::Instruction()
{
}

Instruction::Instruction(Operation opcode, opcode_length length, _register dest,  _register src1,  _register src2)
{
	m_destination = dest;
	m_source1 = src1;
	m_source2 = src2;
	m_opcode = opcode;
	m_length = length;
}

ostream& operator<<(ostream& os, const Instruction& instr)
{
	os << "opcode:" << instr.m_opcode << endl;
	os << "dest reg:" << instr.m_destination << endl;
	os << "m_source1:" << instr.m_source1 << endl;
	os << "m_source2:" << instr.m_source2 << endl;
	return os;
}
