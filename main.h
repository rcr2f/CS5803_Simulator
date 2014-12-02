
#ifndef MAIN_H_
#define MAIN_H_

#include <systemc.h>
#include "instruction.h"

Instruction program1[] = {
    Instruction(Instruction::increment, Instruction::a1, Instruction::a1, Instruction::k),
    Instruction(Instruction::increment, Instruction::a2, Instruction::a2, Instruction::k),
    Instruction(Instruction::multiply, Instruction::x0, Instruction::x1, Instruction::x1),
    Instruction(Instruction::multiply, Instruction::x6, Instruction::x0, Instruction::x2),
    Instruction(Instruction::increment, Instruction::a3, Instruction::a3, Instruction::k),
    Instruction(Instruction::float_add, Instruction::x7, Instruction::x6, Instruction::x3),
    Instruction(Instruction::increment, Instruction::a7, Instruction::a7, Instruction::k) 
    };

Instruction program2[] = {
    Instruction(Instruction::increment, Instruction::a1, Instruction::a1, Instruction::k),
    Instruction(Instruction::increment, Instruction::a2, Instruction::a2, Instruction::k),
    Instruction(Instruction::multiply, Instruction::x0, Instruction::x1, Instruction::x1),
    Instruction(Instruction::multiply, Instruction::x6, Instruction::x0, Instruction::x2),
    Instruction(Instruction::increment, Instruction::a3, Instruction::a3, Instruction::k),
    Instruction(Instruction::increment, Instruction::a4, Instruction::a4, Instruction::k),
    Instruction(Instruction::multiply, Instruction::x3, Instruction::x3, Instruction::x1),
    Instruction(Instruction::float_add, Instruction::x5,  Instruction::x6, Instruction::x3),
    Instruction(Instruction::float_add, Instruction::x7, Instruction::x5, Instruction::x4),
    Instruction(Instruction::increment, Instruction::a7, Instruction::a7, Instruction::k) };
    
Instruction program3[] = {/*TODO*/};


#endif /* MAIN_H_ */
