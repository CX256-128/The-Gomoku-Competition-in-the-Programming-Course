// This is a C++ style Header File
#pragma once
#include<iostream>
#include<string>
// We define some essential tiny-functions here
// namespace interupt defines many kinds of planned exit ways
// function trans is used to decode the int[][] board into a char[][]
// function dis_trans is used to show the line index in a more understandable way
#define BOARD_SIZE 26
namespace interupt{
    class UserQuitException : public std::exception {
        public:
            const char* what() const noexcept override {
                return "End";
            }
    };
}

inline char trans(int input){
    switch (input)
    {
    case 0:
        /* code */
        return '.';
    case 1:
        return 'o';
    case 2:
        return 'x';
    default:
        return ' ';
    }
}
inline std::string dis_trans(int in){
    if(in<10)
        return "0"+std::to_string(in);
    else
        return std::to_string(in);
}