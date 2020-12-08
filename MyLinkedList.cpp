//
// Sebastian Marquez Alvarez A01632483.
// Aldo Alejandro Degollado Padilla A01638391
// Daniel Cordova Verdugo A01630123
// 29/11/2020.

#include "MyLinkedList.h"

MyLinkedList::MyLinkedList(): head(nullptr), tail(nullptr), size(0) {}

MyLinkedList::~MyLinkedList() {
    while (head != nullptr)
        removeFirst();
}

int MyLinkedList::length() {
    return size;
}

bool MyLinkedList::isEmpty() {
    return head == nullptr;
}

MyNodeLL* MyLinkedList::getAt(string& key) {
    MyNodeLL* current = head;
    while (current != nullptr) {
        if (current->key == key)
            return current;
        current = current->next;
    }
    throw invalid_argument("No se encontró " + key + " en la lista");
}

MyNodeLL* MyLinkedList::getHead() const {
    return head;
}

MyNodeLL* MyLinkedList::getAt(int pos) {
    if (pos >= 0 && pos < size) {
        MyNodeLL* current = head;
        for (int i = 0; i < pos; i++)
            current = current->next;
        return current;
    } else
        throw invalid_argument("No se puede insertar en la posición " + to_string(pos) + " en una lista de tamaño " + to_string(size));
}

void MyLinkedList::insertFirst(MyNodeLL* nodeLL) {
    MyNodeLL* oldHead = head;
    head = nodeLL;
    head->next = oldHead;
    if (tail == nullptr)
        tail = head;
    size++;
}

void MyLinkedList::insertFirst(string key, Record& data) {
    head = new MyNodeLL(data, head, key);
    if (tail == nullptr)
        tail = head;
    size++;
}

void MyLinkedList::removeFirst(){
    if (size > 0) {
        MyNodeLL* tmp = this->head;
        head = head->next;
        size--;
        if (size == 0) {
            tail = nullptr;
        }
        delete tmp;
    } else {
        throw invalid_argument("No se puede borrar el inicio de una lista vacía");
    }
}

void MyLinkedList::removeLast(){
    if (size <= 1) {
        removeFirst();
    } else {
        MyNodeLL* current = head;
        for (int i = 0; i < size - 2; i++) {
            current = current->next;
        }
        this->tail = current;
        delete current->next;
        tail->next = nullptr;
        size--;
    }
}

void MyLinkedList::removeAt(int pos){
    if (pos > 0 && pos < this->size - 1) {
        MyNodeLL* previous = this->head;
        for (int i = 0; i < pos - 1; i++) {
            previous = previous->next;
        }
        MyNodeLL* current = previous->next;
        previous->next = current->next;
        delete current;
        size--;
    }
    else if (pos == size - 1)
        removeLast();
    else if (pos == 0)
        removeFirst();
    else
        throw invalid_argument("No se puede borrar un elemento afuera del rango de la lista ");
}

void MyLinkedList::removeAt(string& key) {
    if (isEmpty())
        throw invalid_argument("La lista esta vacia, no se puede eliminar ningun elemento");
    MyNodeLL* current = head;
    if (current->key == key) {
        removeFirst();
        return;
    }
    current = current->next;
    MyNodeLL* previous = head;
    while (current->next != nullptr) {
        if (current->key == key) {
            previous->next = current->next;
            delete current;
            size--;
            return;
        }
    }
    current = current->next;
    previous = previous->next;
    if (current->key == key) {
        previous->next = current->next;
        tail = previous;
        delete current;
        size--;
        return;
    }
    throw invalid_argument("No se puede borrar, no hay ningun elemento con la llave recibida");
}

void MyLinkedList::sortList() {
    MyNodeLL* currentNode = head;
    while (currentNode != nullptr) {
        sort(currentNode->data.begin(), currentNode->data.end());
        currentNode = currentNode->next;
    }
}