//
// Sebastian Marquez Alvarez A01632483.
//
//
//
// 08/12/2020.

#include "Record.h"
#include <algorithm>

void loadFile(MyHashTable& records);

int main() {
    vector<Record> records;
    loadFile(records);
    return 0;
}

void loadFile(vector<Record>& records) {
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
        records.push_back(newRecord);
        records.sort();
    }
    recordsFile.close();
    records.sortHash();
}