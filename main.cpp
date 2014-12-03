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

#include "main.h"


//prompts user for which processor to run and returns the int corresponding to it
int get_processor_choice();

//prompts user for which program to run and returns the int corresponding to it
int get_program_choice();

int sc_main (int argc, char* argv[])
{
	// Print a greeting
	cout << endl << "Welcome to the CDC6600/CDC7600 simulator " << endl;

	int processor_selection = get_processor_choice();
	if (0 == processor_selection)
		return (0);
		
	int program_selection = get_program_choice();
	if (0 == program_selection)
		return (0);

	instruction_fifo_pipeline instruction_buf("what is this?");
	sc_start(30, SC_NS);

	return (0);
}

int get_processor_choice()
{
	int processor_selection;
	// Determine which processor to simulate
	cout << "Select the processor."<< endl;
	cout << "\t1. CDC6600" << endl;
	cout << "\t2. CDC7600" << endl;
	cin >> processor_selection;

	if (1 != processor_selection && 2 != processor_selection)
	{
		cout << "Invalid Input. Terminating program."<< endl;
		return 0;
	}
	return processor_selection;
}


int get_program_choice()
{
	int program_selection = 0;
 	// Prompt the user to select which program to run
	cout << endl<< "Select the input to this program from the list below."<< endl;
	cout << "\t1. Y = A*X^2 + B" << endl;
	cout << "\t2. Y = A*X^2 + B*X + c" << endl;
	cout << "\t3. Y = A*X^2 + B*X + c (X and Y are vectors of length 5)"<< endl;
	cin >> program_selection;
	
	if (3 != program_selection && 2 != program_selection && 1 != program_selection)
	{
		cout << "Invalid Input. Terminating program."<< endl;
		return 0;
	}
	
	return program_selection;
}
