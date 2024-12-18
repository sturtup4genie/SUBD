#pragma once
#include <vector>
#include <ostream>

/**
 * @brief Пространство имён для стека.
 *
 * Содержит реализацию класса Stack.
 */
namespace stack {
    /**
     * @brief Класс Стек.
     *
     * Реализует базовые операции для работы со стеком: добавление, удаление, просмотр верхнего элемента.
     */
    class Stack {
    private:
        /**
         * @brief Вектор для хранения элементов стека.
         */
        std::vector<int> data;

    public:
        /**
         * @brief Конструктор стека.
         */
        Stack();

        /**
         * @brief Деструктор стека.
         */
        ~Stack();

        /**
         * @brief Добавляет элемент в стек.
         * @param value Значение элемента для добавления.
         */
        void push(int value);

        /**
         * @brief Удаляет верхний элемент из стека.
         * @throws std::runtime_error Если стек пуст.
         */
        void pop();

        /**
         * @brief Возвращает верхний элемент стека.
         * @return Значение верхнего элемента.
         * @throws std::runtime_error Если стек пуст.
         */
        int top() const;

        /**
         * @brief Проверяет, пуст ли стек.
         * @return true, если стек пуст, иначе false.
         */
        bool isEmpty() const;

        /**
         * @brief Возвращает строковое представление стека.
         * @return Строка с элементами стека.
         */
        std::string toString() const;

        /**
         * @brief Выводит содержимое стека в указанный поток.
         * @param os Поток для вывода.
         * @param stack Стек для вывода.
         * @return Поток вывода.
         */
        friend std::ostream& operator<<(std::ostream& os, const Stack& stack);

        /**
         * @brief Считывает элементы стека из указанного потока.
         * @param is Поток для ввода.
         * @param stack Стек для заполнения.
         * @return Поток ввода.
         */
        friend std::istream& operator>>(std::istream& is, Stack& stack);
    };
} // namespace stack

