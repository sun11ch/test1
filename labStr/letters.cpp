#include "letters.hpp"
void printLetters(){
    for (int code = 32; code < 123; code++){
        if (code == 32) std::cout << char(0) << " - " << "0" << std::endl;
        if (code == 44) std::cout << char(code) << " - " << code << std::endl;
        if (code == 46) std::cout << char(code) << " - " << code << std::endl;
        if (code == 47) std::cout << char(code) << " - " << code << std::endl;
        if (code > 47 && code < 58){
            std::cout << char(code) << " - "<< code << std::endl;
            if (code == 57) std::cout << "----" << std::endl;
        }
        if (code > 64 && code < 91){
            std::cout << char(code) << " - "<< code << std::endl;
            if (code == 90) std::cout << "----" << std::endl;
        }
        if (code > 96 && code < 123){
            std::cout << char(code) << " - "<< code << std::endl;
        }
    }
    std::cout << "----" << std::endl;
    for (int code = 192; code < 256; code++) {
        if (code > 191 && code < 224){
            std::cout << char(code) << " - "<< code << std::endl;
            if (code == 197) std::cout << char(168) << " - " << "168" << std::endl;
            if (code == 223) std::cout << "----" << std::endl;
        }
        if (code > 223 && code < 256) {
            std::cout << char(code) << " - "<< code << std::endl;
            if (code == 229) std::cout << char(184) << " - " << "184" << std::endl;
        }
    }
 
}