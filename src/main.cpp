#include "VM_temp.h"
#include "types_and_data.h"
#include<iostream>


//template
int main(void){
    VM::VM_temp vm;
    std::vector<i32> prog{4, 5, 1073741829,1073741824};
    vm.loadProg(prog);
    vm.run();
    return 0;
}
