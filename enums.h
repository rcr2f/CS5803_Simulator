/*
 * enums.h
 *
 *      Author: rebecca
 */
 
#ifndef ENUMS_H_
#define ENUMS_H_

enum _register {
	x0,
    x1,
    x2,
    x3,
    x4,
    x5,
    x6,
    x7,
    a0,
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    b0,
    b1,
    b2,
    b3,
    b4,
    b5,
    b6,
    b7,
    k
 };
        
enum Operation {
	fixed_add,
	float_add,
	boolean,
	shift,
	branch,
	divide,
	multiply,
	increment
};
		
enum opcode_length {
	SHORT,
    LONG
};

enum Unit {
	fixed_adder,
	float_adder,
	bool_unit,
	shifter,
	brancher,
	divider,
	multiplier1,
	multiplier2,
	incrementer1,
	incrementer2
};

#endif /* ENUMS_H_*/
