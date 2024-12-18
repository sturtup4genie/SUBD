#include <iostream>
#include "Stack.h"

using namespace stack;

int main() {
    setlocale(LC_ALL, "Russian");

    Stack stack;

    // Добавление элементов в стек
    stack.push(10);
    stack.push(20);
    stack.push(30);
    std::cout << "Стек после добавления элементов: " << stack << "\n";

    // Получение верхнего элемента
    std::cout << "Верхний элемент: " << stack.top() << "\n";

    // Удаление верхнего элемента
    stack.pop();
    std::cout << "Стек после удаления верхнего элемента: " << stack << "\n";

    // Ввод элементов через поток
    std::cout << "Введите элементы для стека через пробел (завершите ввод любым символом): ";
    std::cin >> stack;
    std::cout << "Стек после ввода: " << stack << "\n";

    return 0;
}
