/*
 * programs.h
 *
 *      Author: rebecca
 */

#ifndef PROGRAMS_H_
#define PROGRAMS_H_



Instruction program1[] = {
    Instruction(increment, LONG, a1, a1, k, 0),
    Instruction(increment, LONG, a2, a2, k, 1),
    Instruction(multiply, SHORT, x0, x1, x1, 2),
    Instruction(multiply, SHORT, x6, x0, x2, 3),
    Instruction(increment, LONG, a3, a3, k, 4),
    Instruction(float_add, SHORT, x7, x6, x3, 5),
    Instruction(increment, LONG, a7, a7, k, 6) 
    };
    
Instruction program2[] = {
    Instruction(increment, LONG, a1, a1, k, 0),
    Instruction(increment, LONG, a2, a2, k, 1),
    Instruction(multiply, SHORT, x0, x1, x1, 2),
    Instruction(multiply, SHORT, x6, x0, x2, 3),
    Instruction(increment, LONG, a3, a3, k, 4),
    Instruction(increment, LONG, a4, a4, k, 5),
    Instruction(multiply, SHORT, x3, x3, x1, 6),
    Instruction(float_add, SHORT, x5,  x6, x3, 7),
    Instruction(float_add, SHORT, x7, x5, x4, 8),
    Instruction(increment, LONG, a7, a7, k, 9) 
    };
    
Instruction program3[] = {
	Instruction(increment, LONG, a1, a1, k, 0),
	Instruction(increment, LONG, b0, x1, k, 1), 
/*loop:*/	Instruction(increment, LONG, a1, a2, k, 2), 
	Instruction(increment, LONG, a7, a7, k, 3),
	Instruction(increment, LONG, a1, a1, k, 4), 
	Instruction(multiply, SHORT, x0, x1, x1, 5),
	Instruction(increment, LONG, x2, b1, k, 6),
	Instruction(multiply, SHORT, x3, x0, x2, 7),
	Instruction(increment, LONG, x2, b2, k, 8),
	Instruction(multiply, SHORT, x4, x1, x2, 9),
	Instruction(float_add, SHORT, x3, x3, x4, 10),
	Instruction(increment, LONG, x2, b3, k, 11),
	Instruction(float_add, SHORT, x7, x2, x3, 12),
	Instruction(increment, LONG, b0, b0, k, 13),
	Instruction(increment, LONG, a7, a7, k, 14),
	Instruction(branch, SHORT, -13, 15)
	};

int size[] = {0, 7, 10, 72};

int program_3_loop = 5;


#endif /*  PROGRAMS_H_ */
