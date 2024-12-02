// tests/VectorTests.cpp

#include <iostream>
#include "Vector.h"

void testConstructor() {
    Vector<int> vec;
    std::cout << "Constructor test passed.\n";
}

void testAddAndGet() {
    Vector<int> vec;
    vec.add(5);
    vec.add(10);
    std::cout << (vec.get(0) == 5 && vec.get(1) == 10 ? "Add and Get test passed.\n" : "Add and Get test failed.\n");
}

void testUpdate() {
    Vector<int> vec;
    vec.add(5);
    vec.update(0, 15);
    std::cout << (vec.get(0) == 15 ? "Update test passed.\n" : "Update test failed.\n");
}

void testRemove() {
    Vector<int> vec;
    vec.add(5);
    vec.add(10);
    vec.remove(0);
    std::cout << (vec.get(0) == 10 ? "Remove test passed.\n" : "Remove test failed.\n");
}

void testIterator() {
    Vector<int> vec;
    vec.add(5);
    vec.add(10);
    std::cout << "Iterator test: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

int main() {
    testConstructor();
    testAddAndGet();
    testUpdate();
    testRemove();
    testIterator();
    return 0;
}
