//
// Sebastian Marquez Alvarez A01632483.
//
//
// 08/12/2020.

#include "Records.h"

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
    std::cout << "Introduzca el rango de anios a buscar: " << std::endl << "Busqueda entre el anio: " << std::endl;
    std::cin >> rangeInit;
    std::cout << "...y el anio: " << std::endl;
    std::cin >> rangeFinal;
    bool found = false;
    for (const auto& i: this->data) {
        if (rangeInit <= i.year && i.year <= rangeFinal) {
            std::cout << i << std::endl;
            found = true;
        }
    }
    if (!found)
        std::cout << "No se encontro ningun resultado en el rango solicitado" << std::endl;
}

void Records::get_by_brand() {
    std::string brand;
    std::cout << "Introduzca marca a buscar: " << std::endl;
    std::cin >> brand;
    bool found = false;
    for (const auto& i: this->data) {
        if (brand == i.brand) {
            std::cout << i << std::endl;
            found = true;
        }
    }
    if (!found)
        std::cout << "No se encontro ningun resultado con la marca solicitada" << std::endl;
}

void Records::get_by_media() {
    std::string media;
    std::cout << "Introduzca media a buscar: " << std::endl;
    std::cin >> media;
    bool found = false;
    for (const auto& i: this->data) {
        if (media == i.media) {
            std::cout << i << std::endl;
            found = true;
        }
    }
    if (!found)
        std::cout << "No se encontro ningun resultado con la marca solicitada" << std::endl;
}

void Records::get_by_price() {
    int rangeInit;
    int rangeFinal;
    std::cout << "Introduzca el rango de precio a buscar: " << std::endl << "Busqueda entre el precio: " << std::endl;
    std::cin >> rangeInit;
    std::cout << "...y el precio: " << std::endl;
    std::cin >> rangeFinal;
    bool found = false;
    for (const auto& i: this->data) {
        if (rangeInit <= i.price && i.price <= rangeFinal) {
            std::cout << i << std::endl;
            found = true;
        }
    }
    if (!found)
        std::cout << "No se encontro ningun resultado en el rango solicitado" << std::endl;
}