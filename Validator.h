#ifndef AJIO_VALIDATOR_H
#define AJIO_VALIDATOR_H
#include <string>
#include <iostream>

class Validator {
    void checkWhitespaces(std::string& stringToAnalyze);
    bool checkCommas(std::string& stringToAnalyze);
    bool checkASCII(std::string& stringToAnalyze);
    bool checkContent(std::string& stringToAnalyze);
public:
    Validator(){
        std::cout<<"Validator constructor"<<std::endl;
    }
    bool validate(std::string& stringToAnalyze);
    ~Validator(){
        std::cout<<"Validator destructor"<<std::endl;
    }
};


#endif //AJIO_VALIDATOR_H
