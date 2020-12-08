// Definition of class Record
// Sebastian Marquez Alvarez A01632483.
//
//
//
// 08/12/2020.


#ifndef ACT5_2_RECORD_H
#define ACT5_2_RECORD_H

#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

struct Record {
    //Atributes:
    std::string id;
    int year;
    std::string brand;
    std::string collection;
    std::string character;
    std::string media;
    int price;

    //Constructor:
    explicit Record(const std::string& info);

};

// Operator overloads:
ostream& operator<<(std::ostream& os, const Record& obj);

#endif //ACT5_2_RECORD_H