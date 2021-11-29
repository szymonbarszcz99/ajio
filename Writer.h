#ifndef AJIO_WRITER_H
#define AJIO_WRITER_H
#include <fstream>
#include <iostream>
#include <vector>
#include <tuple>

class Writer {
    std::fstream output;
    std::vector<std::tuple<std::string,std::string,std::string>> stationsVec;
public:
    Writer();
    ~Writer(){
        std::cout<<"Writer destructor"<<std::endl;
    }
    void append(std::string name, std::string link, std::string path);
    void deleteLast();
    const std::vector<std::tuple<std::string,std::string,std::string>>& getVector();
};


#endif //AJIO_WRITER_H
