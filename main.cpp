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
#include "instruction_buffer.cpp"


//prompts user for which processor to run and returns the int corresponding to it
int get_processor_choice();

//prompts user for which program to run and returns the int corresponding to it
int get_program_choice();

int sc_main (int argc, char* argv[])
{
	// Print a greeting
	cout << endl << "Welcome to the CDC6600/CDC7600 simulator " << endl;

	int processor_selection = get_processor_choice();
	bool is_CDC6600 = false;
	if (0 == processor_selection)
		return (0);
	else if (1 == processor_selection)
		is_CDC6600 = true;
		
	int program_selection = get_program_choice();
	if (0 == program_selection)
		return (0);

	sc_signal< bool > clock;
	sc_signal< bool > end;
	sc_signal< bool > processor_choice;
	
	instruction_buffer instruction_buf("instruction_buf");
	instruction_buf.clock(clock);
	instruction_buf.end(end);
	instruction_buf.is_CDC6600(processor_choice);
	instruction_buf.m_program_selection = program_selection;
	processor_choice = is_CDC6600;
	
	clock = 0;
	sc_start(1, SC_NS);
	clock = 1;
	sc_start(1, SC_NS);

	end = false;
	int clock_cycles = 0;
	while(end == false)
	{
		clock = 0;
		sc_start(1, SC_NS);
		clock = 1;
		sc_start(1, SC_NS);
		clock_cycles++;
	}
	
	if(is_CDC6600)
		clock_cycles+=5;
	else
		clock_cycles+=4;

	
	cout << endl << "Simulation complete!" << endl;
	cout << "\tClock Cycles: " << clock_cycles << endl;
	cout << "\tExecution Time: " << sc_time_stamp() << endl << endl;
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
