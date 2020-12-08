//
// Sebastian Marquez Alvarez A01632483.
// Aldo Alejandro Degollado Padilla A01638391
// Daniel Cordova Verdugo A01630123
// 29/11/2020.


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
    std::string month;
    std::string day;
    std::string hour;
    int numberMonth;
    int numberDay;
    int hours;
    int minutes;
    int seconds;

    //Constructor:
    Record(std::string info, string& ip);

    //Member functions:
    std::string info() const;

};

// Operator overloads:
bool operator<(const Record& first, const Record& second);
ostream& operator<<(std::ostream& os, const Record& obj);

#endif //ACT5_2_RECORD_H