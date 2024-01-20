#include "VM_temp.h"
#include "types_and_data.h"
#include<iostream>


//template
int main(void){
    VM::VM_temp vm;
    std::vector<i32> prog{10, 7, 0x40000010,0x40000000};
    vm.loadProg(prog);
    vm.run();
    return 0;
}
