#include "Validator.h"

bool Validator::checkASCII(std::string& stringToAnalyze) {
    return !std::any_of(stringToAnalyze.begin(), stringToAnalyze.end(), [](char c) {
        return static_cast<unsigned char>(c) > 127;
    });
}

bool Validator::checkCommas(std::string& stringToAnalyze) {
    std::size_t commaPos = stringToAnalyze.find(',');
    if(commaPos == std::string::npos){
        std::cout<<"No comma found"<<std::endl;
        return true;
    }
    else return false;
}

void Validator::checkWhitespaces(std::string& stringToAnalyze) {
    while(std::isspace(stringToAnalyze[0]) || stringToAnalyze[0] == '\n')
        stringToAnalyze.erase(0,1);
    while(std::isspace(stringToAnalyze.back()) || stringToAnalyze.back() == '\n')
        stringToAnalyze.erase(stringToAnalyze.end() - 1);

    std::cout<<"String after removing whitespaces: "<<stringToAnalyze<<std::endl;
}

bool Validator::validate(std::string& stringToAnalyze) {
    std::cout<<"Analyzing: "<< stringToAnalyze<<std::endl;
    checkWhitespaces(stringToAnalyze);
    return checkContent(stringToAnalyze) && checkCommas(stringToAnalyze) && checkASCII(stringToAnalyze);
}

bool Validator::checkContent(std::string &stringToAnalyze) {
    if(stringToAnalyze.empty())return false;
    else return true;
}
