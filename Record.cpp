// Implementation of class Record
// Sebastian Marquez Alvarez A01632483.
//
//
// 08/12/2020.

#include "Record.h"



Record::Record(const std::string& info) {
    std::stringstream ss(info);
    std::string buff;

    getline(ss, buff, ',');
    this->id = buff;
    getline(ss, buff, ',');
    this->year = stoi(buff);
    getline(ss, buff, ',');
    this->brand = buff;
    getline(ss, buff, ',');
    this->collection = buff;
    getline(ss, buff, ',');
    this->character = buff;
    getline(ss, buff, ',');
    this->media = buff;
    getline(ss, buff, '\0');
    this->price = stoi(buff);
}

ostream& operator<<(std::ostream& os, const Record& obj) {
    os << obj.id << ",";
    os << obj.year << ",";
    os << obj.brand << ",";
    os << obj.collection << ",";
    os << obj.character << ",";
    os << obj.media << ",";
    os << obj.price << "";
    return(os);
}

