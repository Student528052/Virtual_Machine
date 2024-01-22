#include "assembler.h"
#include "types_and_data.h"
#include "lexer.h"
#include <string>
#include <fstream>
#include <type_traits>
#include <vector>


VM::assembler::assembler(std::string & fname){
	//create input files
	std::ifstream file; 
	file.open(fname); 

	if(file.is_open())  throw std::invalid_argument("File not found") ; 

	std::string line; 
	std::string buf; 
	while (std::getline(file, line)) buf += line + "\n"; 

	file.close(); 

	//parse the file
	VM::lexer lex; 
	std::vector<std::string>tokens = lex.lex(buf); 
	std::vector<uint32_t> instructions = compile_instructions( tokens); 


	//write to output
	std::ofstream output; 
	output.open(fname + ".out.bin", std::ios::binary); //output file in binary format
	
	for (uint32_t i = 0; i < instructions.size(); i++) {
		output.write(reinterpret_cast<char *>(&instructions[i]), sizeof(uint32_t));
	}
	output.close();

}

VM::assembler::assembler(const char * fname):m_fname{fname}{
	std::string sfname{m_fname}; 
	sfname += ".out.bin";


	//create input files
	std::ifstream file; 
	file.open(fname); 

	if(!file.is_open())  throw std::invalid_argument("File not found") ; 

	std::string line; 
	std::string buf; 
	while (std::getline(file, line)) buf += line + "\n"; 

	file.close(); 

	//parse the file
	VM::lexer lex; 
	std::vector<std::string>tokens = lex.lex(buf); 
	std::vector<uint32_t> instructions = compile_instructions( tokens); 


	//output
	m_file = std::fopen(sfname.data(), "wb"); 

	

    for (uint32_t i = 0; i < instructions.size(); i++) {
        // Write each element of the vector to the file
        std::fwrite(&instructions[i], sizeof(uint32_t), 1, m_file);
    }

    std::fclose(m_file); 
}


//compiles the entire file.
 std::vector<uint32_t> VM::assembler::compile_instructions(std::vector<std::string> & str){
	 std::vector<uint32_t> instructions; 
	 //go through each line
	 for(size_t  i = 0; i < str.size(); ++i){

		 if( isInt(str[i]) )  instructions.push_back(std::stoi(str[i])); 
		 else{ //go through each char in the string
			 for(char c: str[i]){
			 uint32_t instruction = map_to_intstuction(c); 
			  instructions.push_back(instruction); 
			 }
		 
		 }
	 }
	 instructions.push_back(0x40000000); // add halt at the end

	 return instructions; 

}

bool VM::assembler::isInt(std::string  str){
	for(uint32_t i = 0; i< str.length(); ++i){
		if(!isdigit(str[i])) return false; 
	}
	return true; 

}

uint32_t  VM::assembler::map_to_intstuction(char & c){


	switch(c){
		case PLUS: return 0x40000001;  
		case MINUS: return 0x40000002;  
		case MULTI: return 0x40000003;  
		case DIVIDE: return 0x40000004;  

			     //pray to whatever god you want  we don't get this
		default: return -1; 
	
	}
	
	return -1; 

}

std::FILE * VM::assembler::getFile(){return m_file; }
std::string  VM::assembler::getFileName(){return m_fname + ".out.bin";}

