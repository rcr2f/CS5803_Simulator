
#ifndef MAIN_H_
#define MAIN_H_

#include <systemc.h>
#include "instruction.h"

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
    Instruction(increment, LONG, a7, a7, k) };
    
Instruction program3[] = {/*TODO*/};


#endif /* MAIN_H_ */
