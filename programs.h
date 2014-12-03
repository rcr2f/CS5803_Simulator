/*
 * programs.h
 *
 *      Author: rebecca
 */

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
	/*TODO once everything else is done...changing 63 lines of code is too much work*/
	};

int size[] = {0, 7, 10, 63};
