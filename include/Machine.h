#pragma once
#define STACK_VM_H
#include <iostream>
#include <vector>
/**
 * @file Machine.h
 * @brief Machine class for initializind the Virtual machine
 * @author Aleksandar Dikov (528052)
 * @version 
 * @date 2024-01-22
 */


namespace VM{
	

	/**
	 * @brief Machine class that initializes the virtual machine and runs the binary file as it's input
	 */
    class Machine{

    public:


	    /**
	     * @brief Constructor that allocates memory 
	     */
        Machine();
	
	/**
	 * @brief Run function to start the machine, provided it's loaded a program, 
	 */
        void run();
	/**
	 * @brief load Program into memory 
	 *
	 * @param prog array of instructions (in binary format) to be loaded into memory 
	 */
        void loadProg(std::vector<uint32_t> prog);
	/**
	 * @brief load Program into memory. This function loades the instructions as command line arguments. 
	 *
	 * @param argc argument count
	 * @param argv[] array of arguments
	 */
	void loadProg(int argc, char* argv[]); 

    private:
	/**
	 * @brief 
	 */
        uint32_t pc = 100;
	/**
	 * @brief 
	 */
        uint32_t sp = 0;
	/**
	 * @brief memory vector
	 */
        std::vector<uint32_t> memory;
	/**
	 * @brief data type
	 */
        uint32_t typ = 0;
	/**
	 * @brief data value. It can be a regular number or an instruction
	 */
        uint32_t dat = 0;
	/**
	 * @brief running status
	 */
        uint32_t running = 1;

	/**
	 * @brief GetType function that checks the first 2 bits of the data. 
	 *
	 * @param instruction single value from the memory array. 
	 *
	 * @return Returns a number that corresponds to weather it's an positive Number, a negative, or a Primitive intruction. 
	 */
        uint32_t GetType(uint32_t instruction);
	/**
	 * @brief GetDatafucntion that checks the last 30 bits of the data. 
	 *
	 * @param instruction single value from the memory array. 
	 *
	 * @return Returns the value of the data. 
	 */
        uint32_t GetData(uint32_t instruction);
	/**
	 * @brief moves the position counter upwords to the next data in the array. 
	 */
        void fetch();
	/**
	 * @brief Decode function that gets the datatype and data itself from the memory array. 
	 */
        void decode();
	/**
	 * @brief Execute function based on data type. 
	 *
	 * If the data type is an instruction, run the primitive() function. 
	 */
        void execute();
	/**
	 * @brief Primitive function. 
	 * This function checks the data ONLY when it is of type Intrruction. It goes over all 8 instructions and preforms the logical operations for the current data and the prefious one in the stack
	 */
        void primitive();
};
}//namespace VM
