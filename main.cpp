// src/main.cpp

#include <iostream>
#include "Vector.h"

int main() {
    // Пример использования шаблонного класса Vector с типом int
    Vector<int> intVector;

    // Добавление элементов в вектор
    intVector.add(1);
    intVector.add(2);
    intVector.add(3);

    std::cout << "Vector intVector after add elements: " << intVector << "\n";

    // Получение элемента по индексу
    try {
        int value = intVector.get(1);
        std::cout << "Element with index 1: " << value << "\n";
    }
    catch (const std::out_of_range& e) {
        std::cerr << e.what() << "\n";
    }

    // Обновление элемента по индексу
    intVector.update(1, 20);
    std::cout << "Vector intVector after update element with index 1: " << intVector << "\n";

    // Удаление элемента
    intVector.remove(1);
    std::cout << "Vector intVector after delete element with index 1: " << intVector << "\n";

    // Использование итератора для прохода по элементам вектора
    std::cout << "Elements intVector with using iterator: ";
    for (auto it = intVector.begin(); it != intVector.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // Пример использования Vector с типом double
    Vector<double> doubleVector;
    doubleVector.add(1.1);
    doubleVector.add(2.2);
    doubleVector.add(3.3);
    std::cout << "Vector doubleVector: " << doubleVector << "\n";

    // Пример использования ввода элементов через поток
    std::cout << "Enter value for intVector separated by a space (complete the input with any character): ";
    std::cin >> intVector;
    std::cout << "intVector after entering from the stream: " << intVector << "\n";

    return 0;
}
