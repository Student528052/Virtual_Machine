
#include <vector>
#include <string> 
namespace VM{

	//TODO: 
	//the goal of this file is to take a file with equasions in RPN and compile them to a binary file for the virtual machine
	class assembler{
		public: 
			assembler() = default; 
			assembler(std::string & fname); 
			assembler(char * fname ); 
			std::vector<uint32_t> compile_instructions(std::vector<std::string> &str); 
			uint32_t map_to_intstuction(char & c); 
			//function to write to file
			void assemble_to(const char * fname); 
		private: 
			bool isInt(std::string  str); 
			//binary file to give to the machine 
			std::FILE  * m_file; 


	
	}; 

}; 
