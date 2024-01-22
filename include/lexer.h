#include <iostream>
#include <vector>
//TODO: add documentation
namespace VM{
	class lexer{
		public: 
			std::vector<std::string> lex ( std::string s); 
		private: 
			bool checkspace(char c); 
			bool checkgroup(char c); 
			char end; 
			char begin; 


	
	}; 


}
