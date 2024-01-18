#include"VM_temp.h"
#include "types_and_data.h"

VM::VM_temp::VM_temp() {
    //Reserve space for 1000000 elements in the memory vector
    memory.reserve(1000000);
}

i32 VM::VM_temp::GetType(i32 instruction) {
    i32 type = 0xc0000000;
    type = (type & instruction) >> 30;
    return type;
}

i32 VM::VM_temp::GetData(i32 instruction) {
    i32 data = 0x3fffffff;
    data = (data & instruction);
    return data;
}

void VM::VM_temp::fetch() {
    pc++;
}

void VM::VM_temp::decode() {
    typ = GetType(memory[pc]);
    dat = GetData(memory[pc]);
}
void VM::VM_temp::execute() {
    if(typ == POS_INT || typ == NEG_INT){
        sp++;
        memory[sp] = dat;
    }else{
        primitive();
    }
}

void VM::VM_temp::primitive() {
    switch(dat){
        case HALT:
            running = 0;
            break;
        case ADD:
            memory[sp - 1] += memory[sp];
            sp--;
        case SUB:
            memory[sp - 1] -= memory[sp];
            sp--;
        case MUL:
            memory[sp - 1] *= memory[sp];
            sp--;
        case DIV:
            memory[sp - 1] /= memory[sp];
            sp--;
    }
}

void VM::VM_temp::run() {
    pc -= 1; //obqsni
    while(running == 1){
        fetch();
        decode();
        execute();
        std::cout << "tos: " << memory[sp] << std::endl;
    }
}

void VM::VM_temp::loadProg(std::vector<i32> prog) {
    for (i32 i = 0; i < prog.size(); ++i) {
        memory[pc + i] = prog[i];
    }
}