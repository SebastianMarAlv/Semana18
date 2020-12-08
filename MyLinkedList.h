//
// Sebastian Marquez Alvarez A01632483.
// Aldo Alejandro Degollado Padilla A01638391
// Daniel Cordova Verdugo A01630123
// 29/11/2020.

#ifndef ACT5_2_MYLINKEDLIST_H
#define ACT5_2_MYLINKEDLIST_H
#include "Record.h"
#include <algorithm>

struct MyNodeLL{
    string key;
    int count;
    vector<Record> data;
    MyNodeLL* next;

    MyNodeLL(Record& data, MyNodeLL* next, string key) {
        this->data.push_back(data);
        this->next = next;
        this->key = key;
        count = 1;
    }
    MyNodeLL(Record& data, string key): MyNodeLL(data, nullptr, key) {}
};

class MyLinkedList{
private:
    MyNodeLL* head;
    MyNodeLL* tail;
    int size;
public:
    MyLinkedList();
    ~MyLinkedList();
    int length();
    bool isEmpty();
    MyNodeLL* getHead() const;
    MyNodeLL* getAt(int pos);
    MyNodeLL* getAt(string& key);
    void insertFirst(MyNodeLL* nodeLL);
    void insertFirst(string key, Record& data);
    void removeFirst();
    void removeLast();
    void removeAt(int pos);
    void removeAt(string& key);
    void sortList();
};
#endif //ACT5_2_MYLINKEDLIST_H
