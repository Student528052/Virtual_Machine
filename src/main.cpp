#include "Machine.h"
#include "types_and_data.h"
#include<iostream>


//template
int main(int argc, char * argv[]){
    VM::Machine vm;
    /*
    std::vector<i32> prog{4, 5, 1073741829,1073741824};
    vm.loadProg(prog);
    */
    
    vm.loadProg(argc, argv); 


    vm.run();
    return 0;
}
