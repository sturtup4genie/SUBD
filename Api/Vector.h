// src/Vector.h

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>
#include <sstream>

/**
 * @brief Cтруктура данных для хранения элементов типа int.
 */
class Vector {
private:
    int* data;          ///< Указатель на массив элементов
    size_t size;        ///< Текущее количество элементов
    size_t capacity;    ///< Вместимость массива

public:
    /**
     * @brief Конструктор вектора.
     * @param init_capacity Начальная вместимость массива (по умолчанию 10).
     */
    Vector(size_t init_capacity = 10)
        : size(0), capacity(init_capacity) {
        data = new int[capacity];
    }

    /**
     * @brief Деструктор вектора.
     * Освобождает память, выделенную под массив.
     */
    ~Vector() {
        delete[] data;
    }

    /**
     * @brief Добавляет элемент в конец вектора.
     * @param value Значение, которое нужно добавить.
     */
    void add(int value) {
        if (size == capacity) {
            resize();
        }
        data[size++] = value;
    }

    /**
     * @brief Получает элемент по индексу.
     * @param index Индекс элемента.
     * @return Значение элемента с указанным индексом.
     * @throws std::out_of_range Если индекс выходит за пределы массива.
     */
    int get(size_t index) const {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    /**
     * @brief Обновляет элемент по указанному индексу.
     * @param index Индекс элемента.
     * @param value Новое значение элемента.
     * @throws std::out_of_range Если индекс выходит за пределы массива.
     */
    void update(size_t index, int value) {
        if (index >= size) throw std::out_of_range("Index out of range");
        data[index] = value;
    }

    /**
     * @brief Удаляет элемент по указанному индексу.
     * @param index Индекс элемента, который нужно удалить.
     * @throws std::out_of_range Если индекс выходит за пределы массива.
     */
    void remove(size_t index) {
        if (index >= size) throw std::out_of_range("Index out of range");
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }

    /**
     * @brief Преобразует содержимое вектора в строку.
     * @return Строковое представление вектора.
     */
    std::string toString() const {
        std::ostringstream oss;
        for (size_t i = 0; i < size; ++i) {
            oss << data[i] << " ";
        }
        return oss.str();
    }

    /**
     * @brief Переопределяет оператор вывода для вектора.
     * @param os Поток вывода.
     * @param vec Вектор, который нужно вывести.
     * @return Поток вывода.
     */
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec) {
        os << vec.toString();
        return os;
    }

    /**
     * @brief Переопределяет оператор ввода для вектора.
     * @param is Поток ввода.
     * @param vec Вектор, в который будут добавлены элементы.
     * @return Поток ввода.
     */
    friend std::istream& operator>>(std::istream& is, Vector& vec) {
        int value;
        while (is >> value) {
            vec.add(value);
        }
        return is;
    }

private:
    /**
     * @brief Увеличивает вместимость массива в два раза.
     */
    void resize() {
        capacity *= 2;
        int* new_data = new int[capacity];
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }
};

#endif // VECTOR_H
