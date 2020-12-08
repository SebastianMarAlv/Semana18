//
// Sebastian Marquez Alvarez A01632483.
//
//
// 08/12/2020.

#include "Records.h"
#include <algorithm>

Records::Records() {
    std::string fileName;
    std::string buff;
    std::stringstream ss;
    std::ifstream recordsFile;
    std::string ip;
    std::cout << "Input file with the records (include extension): "<< std::endl;
    std::cin >> fileName;
    recordsFile.open(fileName, std::ios::in);
    while (recordsFile.fail()) {
        std::cout << "Unable to open \"" << fileName << "\", input file with the records (include extension): ";
        std::cin >> fileName;
        recordsFile.open(fileName, std::ios::in);
    }
    while (recordsFile.is_open() && !recordsFile.eof()) {
        getline(recordsFile, buff);
        Record newRecord(buff);
        data.push_back(newRecord);
    }
}

std::ostream& operator<<(std::ostream& os, const Records& obj) {
    for (const auto& i:obj.data)
        os << i << "/n";
    return os;
}

void Records::get_by_year() {
    int rangeInit;
    int rangeFinal;
    std::cout << "Introduzca el rango de años a buscar: " << std::endl << "Entre el año: " << std::endl;
    std::cin >> rangeInit;
    std::cout << "...y el año: " << std::endl;
    std::cin >> rangeFinal;
    for (const auto& i: this->data) {
        if (rangeInit <= i.year && i.year <= rangeFinal)
            std::cout << i << std::endl;
    }
}

