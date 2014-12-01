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
#include "instruction.h"

int length_of_sequence = 0;

//returns user selection for which processor to simulate
int get_processor();

//returns opcode sequence to use in simulation
Instruction * get_instructions();

int sc_main (int argc, char* argv[])
{
	// Print a greeting
	cout << endl << "Welcome to the CDC6600/CDC7600 simulator " << endl;

	int processor_selection = get_processor();
	if (0 == processor_selection)
		return (0);
	
	Instruction * instruction_stack=get_instructions();
	if(instruction_stack == NULL)
		return (0);
		
	for(int i =0; i<length_of_sequence; i++)
		cout << instruction_stack[i].m_opcode_number << endl;
	
	//delete[] instruction_stack;

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


Instruction * get_instructions()
{
	Instruction * instruction_stack;
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

	length_of_sequence = ((int)inFileInstructions.get()-48)*10 + ((int)inFileInstructions.get()-48);
	instruction_stack = new Instruction[length_of_sequence];

	int count = 0; 
	char temp = inFileInstructions.get();
	while (inFileInstructions.good() && count < length_of_sequence) 
	{
		instruction_stack[count].set_opcode(((int)inFileInstructions.get()-48)*10 + ((int)inFileInstructions.get()-48));
		count++;
		temp = inFileInstructions.get();
	}
	
	return instruction_stack;
}
