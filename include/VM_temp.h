#pragma once
#define STACK_VM_H
#include <iostream>
#include <vector>

typedef int32_t i32;

namespace VM{
    class VM_temp{
    public:
        VM_temp();
        void run();
        void loadProg(std::vector<i32> prog);

    private:
        i32 pc = 100;
        i32 sp = 0;
        std::vector<i32> memory;
        i32 typ = 0;
        i32 dat = 0;
        i32 running = 1;

        i32 GetType(i32 instruction);
        i32 GetData(i32 instruction);
        void fetch();
        void decode();
        void execute();
        void primitive();
};
}
