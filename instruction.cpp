
#include "instruction.h"


Instruction::Instruction()
{
}


void Instruction::set_opcode(int opcode)
{
	m_opcode_number = opcode;
	m_time_to_execute = set_execution_time();
	m_is_long = set_length_of_opcode();
}

int Instruction::set_execution_time()
{
	switch(m_opcode_number) {
		case 0:
			return 0;
		case 1:
		case 2:
			return 14;
		case 3:
			return 9;
		case 4:
		case 5:
		case 6:
		case 7:
			return 8;
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
			return 3;
		case 20:
		case 21:
		case 22:
		case 23:
		case 26:
		case 27:
		case 43:
			return 3;
		case 24:
		case 25:
			return 4;
		case 30:
		case 31:
		case 32:
		case 33:
		case 34:
		case 35:
			return 5;
		case 44:
		case 45:
			return 29;
		case 47:
			return 8;
		case 40:
		case 41:
		case 42:
			return 10;
		case 50:
		case 51:
		case 52:
		case 53:
		case 54:
		case 55:
		case 56:
		case 57:
		case 60:
		case 61:
		case 62:
		case 63:
		case 64:
		case 65:
		case 66:
		case 67:
		case 70:
		case 71:
		case 72:
		case 73:
		case 74:
		case 75:
		case 76:
		case 77:
			return 3;
		default:
			return 0;
		}
}

bool Instruction::set_length_of_opcode()
{
	switch(m_opcode_number) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 50:
		case 51:
		case 52:
		case 60:
		case 61:
		case 62:
		case 70:
		case 71:
		case 72:
			return true;
		default:
			return false;
		}
}
