#include "Stack.h"
#include <stdexcept>
#include <sstream>

namespace stack {
    // Конструктор
    Stack::Stack() {}

    // Деструктор
    Stack::~Stack() {}

    // Добавление элемента
    void Stack::push(int value) {
        data.push_back(value);
    }

    // Удаление элемента
    void Stack::pop() {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        data.pop_back();
    }

    // Возврат верхнего элемента
    int Stack::top() const {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        return data.back();
    }

    // Проверка на пустоту
    bool Stack::isEmpty() const {
        return data.empty();
    }

    // Преобразование стека в строку
    std::string Stack::toString() const {
        std::ostringstream oss;
        for (int value : data) {
            oss << value << " ";
        }
        return oss.str();
    }

    // Вывод стека в поток
    std::ostream& operator<<(std::ostream& os, const Stack& stack) {
        os << stack.toString();
        return os;
    }

    // Ввод элементов в стек из потока
    std::istream& operator>>(std::istream& is, Stack& stack) {
        int value;
        while (is >> value) {
            stack.push(value);
        }
        return is;
    }
} // namespace stack
