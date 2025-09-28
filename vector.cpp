#include "vector.h"

//Vector definitions
Vector::Vector() {
    capacity = 2;
    size = 0;
    vector = new int[capacity];
}

Vector::Vector(int capacity) {
    this->capacity = capacity;
    size = 0;
    vector = new int[capacity];
}

Vector::~Vector() {
    delete [] vector;
}


int  Vector::at(int index) const {
    if (index < size && index >= 0) {
        return vector[index];
    }
    return -1;
}

void Vector::clear() { //destroy elements and set size to 0
    delete [] vector;
    vector = new int[capacity];
    size = 0;
}

void Vector::increaseCapacity() {
    //double capacity and create new, larger array
    capacity *= 2;
    int* newVector = new int[capacity];

    //copy elements over
    for (int i = 0; i < size; i++) {
        newVector[i] = vector[i];
    }

    //delete old vector and assign vector pointer to the newVector
    delete [] vector;
    vector = newVector;
    newVector = nullptr;

    std::cout << "Increased Capacity\n";
}

void Vector::push_back(int value) {
    if (size < capacity) {
        vector[size] = value;
        size++;
    } else {
        increaseCapacity();
        vector[size] = value;
        size++;
    }
}

void Vector::erase(int index) {
    for (int i = index; i < size; i++) {
        vector[i] = vector[i + 1];
    }
    size--;
}

void Vector::insert(const int pos, const int value) {
    if (size < capacity) {
        shiftRightFromPosition(pos);
        vector[pos] = value;
        size++;
    } else {
        increaseCapacity();
        shiftRightFromPosition(pos);
        vector[pos] = value;
        size++;
    }
}

void Vector::print() const {
    for (int i = 0; i < size; i++) {
        std::cout << vector[i] << " ";
    }
    std::cout << '\n';
}

void Vector::shiftRightFromPosition(const int pos) {
    for (int i = size - 1; i >= pos; i--) {
        vector[i + 1] = vector[i];
    }
}

void Vector::printCapacityAndSize() const {
    std::cout << "Capacity: " << capacity << "\n";
    std::cout << "Size: " << size << "\n";
}
