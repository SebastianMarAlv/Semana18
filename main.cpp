//
// Sebastian Marquez Alvarez A01632483.
// Aldo Alejandro Degollado Padilla A01638391
// Daniel Cordova Verdugo A01630123
// 29/11/2020.

#include "MyHashTable.h"

void loadFile(MyHashTable& records);

int main() {
    MyHashTable records;
    loadFile(records);
    records.getAndPrint();
    return 0;
}

void loadFile(MyHashTable& records) {
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
        Record newRecord(buff, ip);
        records.put(ip, newRecord);

    }
    recordsFile.close();
    records.sortHash();
}