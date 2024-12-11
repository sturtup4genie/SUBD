// src/main.cpp

#include <iostream>
#include "Vector.h"

/**
 * @brief Точка входа в программу.
 * Демонстрирует работу с классом Vector для хранения целых чисел.
 * 
 * @return int Код завершения программы.
 */
int main() {
    setlocale(LC_ALL, "Russian"); // Для корректного отображения русского текста

    /**
     * @brief Создание объекта Vector для хранения элементов типа int.
     */
    Vector intVector;

    /**
     * @brief Добавление элементов в вектор.
     */
    intVector.add(1);
    intVector.add(2);
    intVector.add(3);
    std::cout << "Вектор intVector после добавления элементов: " << intVector << "\n";

    /**
     * @brief Получение элемента по индексу.
     */
    try {
        int value = intVector.get(1);
        std::cout << "Элемент с индексом 1: " << value << "\n";
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << "\n";
    }

    /**
     * @brief Обновление элемента по указанному индексу.
     */
    intVector.update(1, 20);
    std::cout << "Вектор intVector после обновления элемента с индексом 1: " << intVector << "\n";

    /**
     * @brief Удаление элемента по указанному индексу.
     */
    intVector.remove(1);
    std::cout << "Вектор intVector после удаления элемента с индексом 1: " << intVector << "\n";

    /**
     * @brief Пример ввода элементов в вектор через поток.
     */
    std::cout << "Введите значения для intVector через пробел (завершите ввод любым символом): ";
    std::cin >> intVector;
    std::cout << "intVector после ввода из потока: " << intVector << "\n";

    return 0;
}
