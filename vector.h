#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

class Vector {
public:
    //constructors
    Vector();
    Vector(int capacity);

    //destructor
    ~Vector();

    //member functions
    int  at(int index) const;
    int getSize() const { return size; }
    bool isEmpty() const { return size == 0; }
    void clear();
    void increaseCapacity();
    void push_back(int value);
    void erase(int index);
    void insert(const int pos, const int value);
    void print() const;
    void printCapacityAndSize() const;

private:
    void shiftRightFromPosition(const int pos); //helper for insert
    int capacity;
    int size;
    int* vector = nullptr;
};

#endif
