// Header of class MyHashTable.
// Sebastian Marquez Alvarez A01632483.
// Aldo Alejandro Degollado Padilla A01638391
// Daniel Cordova Verdugo A01630123
// 29/11/2020.

#ifndef ACT5_2_MYHASHTABLE_H
#define ACT5_2_MYHASHTABLE_H
#include "MyLinkedList.h"
#include <functional>
#include <cmath>

class MyHashTable{
private:
    int size; // El número de elementos que tiene almacenado.
    int sizeA; // El tamaño del arreglo.
    MyLinkedList* table;
    void rehashing();
    int getPos(string key) const;
public:
    MyHashTable();
    ~MyHashTable();
    bool isEmpty() const;
    void put(string key, Record& data);
    MyNodeLL* get(string key);
    void remove(string key);
    void sortHash();
    void getAndPrint();
};
#endif //ACT5_2_MYHASHTABLE_H