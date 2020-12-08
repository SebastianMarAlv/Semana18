//
// Sebastian Marquez Alvarez A01632483.
// Aldo Alejandro Degollado Padilla A01638391
// Daniel Cordova Verdugo A01630123
// 29/11/2020.

#include "MyHashTable.h"

#include <utility>

MyHashTable::MyHashTable() {
    size = 0;
    sizeA = 10000;
    table = new MyLinkedList[sizeA];
}

MyHashTable::~MyHashTable() {
    delete[] table;
}

// Method that returns if the Hash table is empty. Complexity O(1).
bool MyHashTable::isEmpty() const {
    return size == 0;
}

// Rehashing of the table to ensure low complexity on operations. Complexity O(n).
void MyHashTable::rehashing() {
    MyLinkedList* oldTable = table;
    int oldSizeA = sizeA;
    sizeA = sizeA * 2 + 1;
    table = new MyLinkedList[sizeA];
    for (int i = 0; i < oldSizeA; i++) {
        MyLinkedList* currentList = &oldTable[i];
        while (!currentList->isEmpty()) {
            MyNodeLL* currentNode = currentList->getHead();
            int pos = getPos(currentNode->key);
            table[pos].insertFirst(currentNode);
            currentList->removeFirst();
        }
    }
    delete[] oldTable;
}

// Method that returns the hashed key to use as array index. Complexity O(1).
int MyHashTable::getPos(string key) const {
    size_t hashT = hash<string>{}(key);
    int hashCode = static_cast<int>(hashT);
    return abs(hashCode) % sizeA;
}

// Method that inserts a new element into the Hash Table; does rehashing if necessary. Complexity O(n), average O(1).
void MyHashTable::put(string key, Record& data) {
    float loadFactor = float(size) / float(sizeA);
    if (loadFactor > 0.75) {
        rehashing();
        put(move(key), data);
    } else {
        int pos = getPos(key);
        try {
            MyNodeLL* node = table[pos].getAt(key);
            node->data.push_back(data);
            node->count++;
        } catch(exception e) {
            table[pos].insertFirst(key, data);
            size++;
        }
    }
}

// Method that search a element from the Hash Table. Complexity O(n), average O(1).
MyNodeLL* MyHashTable::get(string key){
    int pos = getPos(key);
    MyLinkedList* list = &table[pos];
    return list->getAt(key);
}

// Method that removes a element from the Hash Table. Complexity O(n), average O(1)..
void MyHashTable::remove(string key){
    int pos = getPos(key);
    MyLinkedList* list = &table[pos];
    list->removeAt(key);
}

void MyHashTable::sortHash() {
    for (int i = 0; i < sizeA; i++){
        MyLinkedList* currentList = &table[i];
        if (currentList != nullptr) {
            currentList->sortList();
        }
    }
}

void MyHashTable::getAndPrint() {
    string ip;
    cout << "Introduzaca la ip a buscar:" << endl;
    cin >> ip;
    MyNodeLL* NodeLL = get(ip);
    cout << NodeLL->key << endl;
    cout << NodeLL->count << endl;
    for (int i = 0; i < NodeLL->data.size(); i++)
        cout << NodeLL->data[i] << endl;
}