//
// Sebastian Marquez Alvarez A01632483.
//
//
// 08/12/2020.

#include "Records.h"

Records::Records() {
    string fileName;
    string buff;
    stringstream ss;
    ifstream recordsFile;
    string ip;
    cout << "Input file with the records (include extension): "<< endl;
    cin >> fileName;
    recordsFile.open(fileName, ios::in);
    while (recordsFile.fail()) {
        cout << "Unable to open \"" << fileName << "\", input file with the records (include extension): ";
        cin >> fileName;
        recordsFile.open(fileName, ios::in);
    }
    while (recordsFile.is_open() && !recordsFile.eof()) {
        getline(recordsFile, buff);
        Record newRecord(buff);
        data.push_back(newRecord);
    }
}

ostream& operator<<(std::ostream& os, const Records& obj) {
    for (const auto& i:obj.data)
        os << i << "/n";
    return os;
}
