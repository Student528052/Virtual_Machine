#ifndef VIRTUAL_MACHINE_RNP_H
#define VIRTUAL_MACHINE_RNP_H
#include <iostream>
#include <vector>

//TODO: ask stiliyan about this. 
//we have all the files nessesary.(machine, assembler and lexer)
typedef uint8_t byte;
typedef std::vector<std::string> strings;

enum State : byte {
    START,
    READCHAR,
    READBLOCK,
<<<<<<< HEAD
    DUMP, 
=======
    DUMP,
>>>>>>> 0a29b9fea66b77a98a0ce6d8c6d736996e1a145a
    END
};

class RNP {
    bool my_isspace(char c);
    bool isspecial(char c);
    bool isgroup(char c);
    char end_char, beg_char;
public:
    strings rnp(std::string s);
};

#endif //VIRTUAL_MACHINE_RNP_H
