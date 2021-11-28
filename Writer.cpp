#include "Writer.h"

Writer::Writer() {
    //Clear file
    this->output.open("../stations.csv",std::fstream::out | std::fstream::trunc);
    this->output.close();
}

void Writer::add(std::string name, std::string link, std::string path) {
    if(name[0] == '\n')name.erase(0);
    if(name.back() == '\n')name.erase(name.back());

    this->stationsVec.emplace_back(name,link,path);
    this->output.open("../stations.csv",std::fstream::app);
    this->output<<name<<","<<link<<","<<path<<std::endl;
    this->output.close();
}

void Writer::deleteLast() {
    std::cout<<"Delete last"<<std::endl;
    if(!this->stationsVec.empty()) {

    std::fstream newFile("../stations_temp.csv", std::fstream::app);
    this->output.open("../stations.csv", std::fstream::in);

    std::string tempString;
    for (int i = 1; i < this->stationsVec.size(); i++) {
        getline(this->output, tempString);
        newFile << tempString << std::endl;
    }

    this->output.close();
    remove("../stations.csv");
    rename("../stations_temp.csv", "../stations.csv");

    this->stationsVec.erase(this->stationsVec.end() - 1);

    newFile.close();
    }

}

const std::vector<std::tuple<std::string, std::string, std::string>> &Writer::getVector() {
    return this->stationsVec;
}
