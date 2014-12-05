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
    
Instruction program3[] = {
	Instruction(increment, LONG, a1, a1, k),
	Instruction(increment, LONG, b0, x1, k), 
/*loop:	*/Instruction(increment, LONG, a1, a2, k), 
	Instruction(increment, LONG, a7, a7, k),
	Instruction(increment, LONG, a1, a1, k), 
	Instruction(multiply, SHORT, x0, x1, x1),
	Instruction(increment, LONG, x2, b1, k),
	Instruction(multiply, SHORT, x3, x0, x2),
	Instruction(increment, LONG, x2, b2, k),
	Instruction(multiply, SHORT, x4, x1, x2),
	Instruction(float_add, SHORT, x3, x3, x4),
	Instruction(increment, LONG, x2, b3, k),
	Instruction(float_add, SHORT, x7, x2, x3),
	Instruction(increment, LONG, b0, b0, k),
	Instruction(increment, LONG, a7, a7, k),
	Instruction(branch, SHORT, -13)
	};

int size[] = {0, 7, 10, 16};


#endif /*  PROGRAMS_H_ */
