//
// Sebastian Marquez Alvarez A01632483.
// Aldo Alejandro Degollado Padilla A01638391
// Daniel Cordova Verdugo A01630123
// 29/11/2020.

#include "Record.h"

int mtoi(string month) {
    vector<string> months = {"Jan", "Feb", "Mar",
                             "Apr", "May", "Jun",
                             "Jul", "Aug", "Sep",
                             "Oct", "Nov", "Dec"};

    for (int i = 0; i < 12; i++)
        if (months[i] == month)
            return i + 1;
    return(-1);
}


Record::Record(std::string info, string& ip) {
    std::stringstream ss(info);
    std::string buff;

    getline(ss, buff, ' ');
    this->month = buff;
    getline(ss, buff, ' ');
    this->day = buff;
    getline(ss, buff, ' ');
    this->hour = buff;
    getline(ss, buff, ':');
    ip = buff;
    getline(ss, buff, '\0');
    this->numberMonth = mtoi(this->month);
    this->numberDay = stoi(day);
    ss = stringstream(this->hour);
    getline(ss, buff, ':');
    this->hours = stoi(buff);
    getline(ss, buff, ':');
    this->minutes = stoi(buff);
    getline(ss, buff, '\0');
    this->seconds = stoi(buff);
}

string Record::info() const {
    std::stringstream ss;

    ss << this->month << " ";
    ss << this->day << " ";
    ss << this->hour << " ";
    return(ss.str());
}

bool operator<(const Record& first, const Record& second) {
    if (first.numberMonth != second.numberMonth)
        return first.numberMonth < second.numberMonth;
    else if (first.numberDay != second.numberDay)
        return first.numberDay < second.numberDay;
    else if (first.hour != second.hour)
        return first.hour < second.hour;
    else if (first.minutes != second.minutes)
        return first.minutes < second.minutes;
    else
        return first.seconds < second.seconds;
}

ostream& operator<<(std::ostream& os, const Record& obj) {
    os << obj.info();
    return(os);
}