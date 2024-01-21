//
// Created by Lenovo on 1/20/2024.
//

#ifndef VIRTUAL_MACHINE_RNP_H
#define VIRTUAL_MACHINE_RNP_H
#include <iostream>
#include <vector>

typedef uint8_t byte;
typedef std::vector<std::string> strings;

enum State : byte {
    START,
    READCHAR,
    READBLOCK,
    DUMP, 
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
