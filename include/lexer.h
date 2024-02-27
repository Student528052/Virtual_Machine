#include <iostream>
#include <vector>
/**
     * @class lexer
     * @brief A lexer class for tokenizing strings. Used by assembler.h 
     *
     * This class is designed to tokenize an input string into a vector of tokens based on specific rules defined by the character checks and grouping mechanisms.
     */
namespace VM{
	class lexer{
		public: 
	/**
             * @brief Tokenizes the input string into a vector of strings.
             * 
             * @param s The input string to tokenize.
             * @return std::vector<std::string> A vector containing the tokens extracted from the input string.
             */
			std::vector<std::string> lex ( std::string s); 
		private: 

			/**
			 * @brief function for checking if the string has a space
			 *
			 * @param c input character 
			 *
			 * @return if it is a space or not
			 */
			bool checkspace(char c); 

			/**
			 * @brief checkgroup function 
			 * This function is for checking if the current char and/or the ones after is belong in a group. 
			 * A "Group" in this case is defined as being inside "" or (). 
			 *
			 * @param c input character
			 *
			 * @return  if it's a group symbol or not
			 */
			bool checkgroup(char c); 

			/**
			 * @brief End character
			 */
			char end; 
			/**
			 * @brief begin character
			 */
			char begin; 


	
	}; 


}
