#include "lexer.h"
#include "types_and_data.h"
#include <cctype>
#include <vector>
#define BUFF_SIZE 128

std::vector<std::string> VM::lexer::lex(std::string str){
	std::vector<std::string> strlst; 
	char buf[BUFF_SIZE];
	State state = START; 

	size_t i{0}; 
	size_t j{0}; 
	int balance{0}; 

	while( i < str.length()){
		switch(state){
			case START: 
				if(checkspace(str[i])) state = SKIP; 

				else if (checkgroup(str[i])){

					if(str[i] == '"'){
						buf[j] = str[i]; 
						j++; 
						i++; 
						}
				state = READBLOCK; 
				}

				else state = READCHAR; 
			break; 
			case READCHAR:

				if(checkspace(str[i])) state = DUMP; 

				else if(checkgroup(str[i])){

					if (str[i] == '"') {
					buf[j] = str[i];
					j++;
					i++;
					}
					state = READBLOCK; 
				}else{

				buf[j] = str[i]; 
				j++; 
				i++; 
			}
			break; 

			case READBLOCK: 
			if(str[i] == begin && str[i] != '"'){
				balance ++; 
				buf[j] = str[i];
				j++;
				i++;
			}else if(str[i] == end){
				balance--; 
				buf[j] = str[i];
				j++;
				i++;
				if(balance <=0) state = DUMP; 
			}else {
				buf[j] = str[i];
				j++;
				i++;
			}
			break; 
			case SKIP: 

			if(checkspace(str[i])) i++; 
			else state = READCHAR; 

			break; 
			case DUMP: 
			if(j >0){
				buf[j] = 0; 
				strlst.push_back(buf); 
				j = 0; 
			}
			state = START; 
			break; 
			case END: 
			i = str.length(); 
			break; 
		}
	}
	return strlst; 
}

bool VM::lexer::checkgroup(char c) {

	begin = c;
	switch(c) {
	case '"':
		end = '"';
		return true;

	case '(':
		end = ')';
		return true;

	case ')': return true;
	default:return false;
	}
}
bool VM::lexer::checkspace(char c){return std::isspace(c);}


