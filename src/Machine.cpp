#include"Machine.h"
#include "types_and_data.h"
#include <iostream>
#include <string>

VM::Machine::Machine() {
    //Reserve space for 1000000 elements in the memory vector
    memory.reserve(1000000);
}

uint32_t VM::Machine::GetType(uint32_t instruction) {
    uint32_t type = 0xc0000000;
    type = (type & instruction) >> 30;
    return type;
}

uint32_t VM::Machine::GetData(uint32_t instruction) {
    uint32_t data = 0x3fffffff;
    data = (data & instruction);
    return data;
}

void VM::Machine::fetch() {
    pc++;
}

void VM::Machine::decode() {
    typ = GetType(memory[pc]);
    dat = GetData(memory[pc]);
}
void VM::Machine::execute() {
    if(typ == POS_INT || typ == NEG_INT){
        sp++;
        memory[sp] = dat;
    }else{
        primitive();
    }
}

void VM::Machine::primitive() {
    switch(dat){
        case HALT:
            running = 0;
            break;
        case ADD:
            memory[sp - 1] += memory[sp];
            sp--;
	    break; 
        case SUB:
            memory[sp - 1] -= memory[sp];
            sp--;
	    break;
        case MUL:
            memory[sp - 1] *= memory[sp];
            sp--;
	    break; 
        case DIV:
            memory[sp - 1] /= memory[sp];
            sp--;
	    break;
        case OP_AND:
            memory[sp - 1] = memory[sp-1] & memory[sp];
            sp--;
            break;
        case OP_OR:
            memory[sp - 1] = memory[sp-1] | memory[sp];
            sp--;
            break;
    }
}

void VM::Machine::run() {
    pc -= 1; 
    while(running == 1){
        fetch();
        decode();
        execute();
        std::cout << "tos: " << memory[sp] << std::endl;
    }
}

void VM::Machine::loadProg(std::vector<uint32_t> prog) {

    for (int32_t i = 0; i < static_cast<int32_t>( prog.size()); ++i) {
        memory[pc + i] = prog[i];
    }
}
void VM::Machine::loadProg(int argc, char* argv[] ){
    for (int32_t i = 0; i < argc ; ++i) {
	    //testing
	    //std::cout << "Read" << "\n"; 

        memory[pc + i] = std::atoi(argv[i]);

    }
}
