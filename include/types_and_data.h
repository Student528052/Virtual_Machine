#ifndef VIRTUAL_MACHINE_TYPES_AND_DATA_H
#define VIRTUAL_MACHINE_TYPES_AND_DATA_H

#endif //VIRTUAL_MACHINE_TYPES_AND_DATA_H

enum{
    //pROVERI VUV VIDEOTO ZASHTO SE IZPOLZVA 0 I 2
    POS_INT = 0,
    INSTRUCTION,
    NEG_INT
};

//TODO: change the names to fit for other (custom)syntax
enum{
	PLUS = '+',
	MINUS = '-', 
	MULTI = '*', 
	DIVIDE = '/',
	L_BRAC = '(',
	R_BRAC = ')'
};
enum{
    HALT = 0,
    ADD,
    SUB,
    MUL,
    DIV,
    OP_AND,
    OP_OR, 
    LOD, 
};
