/*
 * programs.h
 *
 *      Author: rebecca
 */

#ifndef PROGRAMS_H_
#define PROGRAMS_H_

Instruction program1[] = {
    Instruction(increment, LONG, a1, a1, k),
    Instruction(increment, LONG, a2, a2, k),
    Instruction(multiply, SHORT, x0, x1, x1),
    Instruction(multiply, SHORT, x6, x0, x2),
    Instruction(increment, LONG, a3, a3, k),
    Instruction(float_add, SHORT, x7, x6, x3),
    Instruction(increment, LONG, a7, a7, k) 
    };
    
Instruction program2[] = {
    Instruction(increment, LONG, a1, a1, k),
    Instruction(increment, LONG, a2, a2, k),
    Instruction(multiply, SHORT, x0, x1, x1),
    Instruction(multiply, SHORT, x6, x0, x2),
    Instruction(increment, LONG, a3, a3, k),
    Instruction(increment, LONG, a4, a4, k),
    Instruction(multiply, SHORT, x3, x3, x1),
    Instruction(float_add, SHORT, x5,  x6, x3),
    Instruction(float_add, SHORT, x7, x5, x4),
    Instruction(increment, LONG, a7, a7, k) 
    };
    /*
Instruction program3[] = {
	Instruction(increment, LONG, , , k),
	Instruction(increment, LONG, , , k), 
/*loop:	Instruction(increment, LONG, , , k), 
	Instruction(increment, LONG, , , k),
	Instruction(increment, LONG, , , k), 
	Instruction(multiply, SHORT, ),
	Instruction(increment, LONG, ),
	Instruction(multiply, SHORT, ),
	Instruction(increment, LONG, ),
	Instruction(multiply, SHORT, ),
	Instruction(float_add, SHORT, ),
	Instruction(increment, LONG, ),
	Instruction(float_add, SHORT, ),
	Instruction(increment, LONG, ),
	Instruction(increment, LONG, ),
	Instruction(branch, ???) //TODO: add constructor for this?
	};*/

int size[] = {0, 7, 10, 63};


#endif /*  PROGRAMS_H_ */
