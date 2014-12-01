/*
 * main.cpp
 *
 *  Created on: Nov 15, 2014
 *      Authors: fred
 * 				 rebecca
 * 
 * To install SystemC on Linux: http://www.how2posts.com/2014/02/how-to-install-systemc-on-your.html
 * To compile:  export SYSTEMC_HOME=/usr/local/systemc-2.3.1
 * 				g++ -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib-linux64 -Wl,-rpath=$SYSTEMC_HOME/lib-linux64 -o CDC_Sim main.cpp -lsystemc -lm
 * 		or
 * 				make
 * To run: ./CDC_Sim
 */
#include <systemc.h>

struct instructions{
	int * opcode_sequence;
	int size_of_array;
	int * time_to_execute;
	bool * is_long;
};

//returns user selection for which processor to simulate
int get_processor();

//returns opcode sequence to use in simulation
instructions get_instructions();

int get_execution_time(int opcode);

bool get_length_of_opcode(int opcode);

int sc_main (int argc, char* argv[])
{
	// Print a greeting
	cout << endl << "Welcome to the CDC6600/CDC7600 simulator " << endl;

	int processor_selection = get_processor();
	if (0 == processor_selection)
		return (0);
	
	instructions instruction_stack=get_instructions();
	if(instruction_stack.opcode_sequence == NULL)
		return (0);
	else
		delete[] instruction_stack.opcode_sequence;
	
	return (0);
}

int get_processor()
{
	int processor_selection;
	// Determine which processor to simulate
	cout << "Select the processor."<< endl;
	cout << "\t1. CDC6600" << endl;
	cout << "\t2. CDC7600" << endl;
	cin >> processor_selection;

	if (1 == processor_selection)
		cout << endl<< "CDC6600" << endl;
	else if (2 == processor_selection)
		cout << endl<< "CDC7600" << endl;
	else
	{
		cout << "Invalid Input. Terminating program."<< endl;
		return 0;
	}
	return processor_selection;
}


instructions get_instructions()
{
	instructions instruction_stack;
	ifstream inFileInstructions;
	int program_selection = 0;
 	// Prompt the user to select which program to run
	cout << endl<< "Select the input to this program from the list below."<< endl;
	cout << "\t1. Y = A*X^2 + B" << endl;
	cout << "\t2. Y = A*X^2 + B*X + c" << endl;
	cout << "\t3. Y = A*X^2 + B*X + c (X and Y are vectors of length 5)"<< endl;
	cin >> program_selection;
	
	if (1 == program_selection)
	{
		inFileInstructions.open("program1.txt",ifstream::in);
		cout << endl<< "program 1" << endl;
	}
	else if (2 == program_selection)
	{
		inFileInstructions.open("program2.txt",ifstream::in);
		cout << endl<< "program 2" << endl;
	}
	else if (3 == program_selection)
	{
		inFileInstructions.open("program3.txt",ifstream::in);
		cout << endl<< "program 3" << endl;
	}
	else
	{
		cout << "Invalid Input. Terminating program."<< endl;
		return instruction_stack;
	}

	instruction_stack.size_of_array = ((int)inFileInstructions.get()-48)*10 + ((int)inFileInstructions.get()-48);
	instruction_stack.opcode_sequence = new int[instruction_stack.size_of_array];
	instruction_stack.time_to_execute = new int[instruction_stack.size_of_array];
	instruction_stack.is_long = new bool[instruction_stack.size_of_array];
	
	int count = 0; 
	char temp = inFileInstructions.get();
	while (inFileInstructions.good() && count<instruction_stack.size_of_array) 
	{
		instruction_stack.opcode_sequence[count] = ((int)inFileInstructions.get()-48)*10 + ((int)inFileInstructions.get()-48);
		instruction_stack.time_to_execute[count] = get_execution_time(instruction_stack.opcode_sequence[count]);
		instruction_stack.is_long[count] = get_length_of_opcode(instruction_stack.opcode_sequence[count]);
		count++;
		temp = inFileInstructions.get();
	}
	
	return instruction_stack;
}


int get_execution_time(int opcode)
{
	switch(opcode) {
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
			
bool get_length_of_opcode(int opcode)
{
	switch(opcode) {
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

