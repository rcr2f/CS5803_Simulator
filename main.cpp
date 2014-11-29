/*
 * main.cpp
 *
 *  Created on: Nov 15, 2014
 *      Authors: fred
 * 				 rebecca
 * 
 * To install SystemC on Linux: http://www.how2posts.com/2014/02/how-to-install-systemc-on-your.html
 * To compile:  export SYSTEMC_HOME=/usr/local/systemc231/
 * 				g++ -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib-linux -o CDC_Sim main.cpp -lsystemc -lm
 * To run: ./CDC_Sim
 */
#include <systemc.h>

int sc_main (int argc, char* argv[])
{
	// Print a greeting
	cout << endl << "Welcome to the CDC6600/CDC7600 simulator " << endl;

	int processor_selection = 0;
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
		return (0);
	}

	int program_selection = 0;
 	// Prompt the user to select which program to run
	cout << endl<< "Select the input to this program from the list below."<< endl;
	cout << "\t1. Y = A*X^2 + B" << endl;
	cout << "\t2. Y = A*X^2 + B*X + c" << endl;
	cout << "\t3. Y = A*X^2 + B*X + c (X and Y are vectors of length 5)"<< endl;
	cin >> program_selection;

	if (1 == program_selection)
		cout << endl<< "program 1" << endl;
	else if (2 == program_selection)
		cout << endl<< "program 2" << endl;
	else if (3 == program_selection)
		cout << endl<< "program 3" << endl;
	else
	{
		cout << "Invalid Input. Terminating program."<< endl;
		return (0);
	}

	return (0);
}



