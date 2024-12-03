// src/Vector.h

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>
#include <sstream>

template <typename T>
class Vector {
private:
    T* data;            // указатель на массив элементов
    size_t size;        // текущее количество элементов
    size_t capacity;    // вместимость массива

public:
    // Конструктор
    Vector(size_t init_capacity = 10)
        : size(0), capacity(init_capacity) {
        data = new T[capacity];
    }

    // Деструктор
    ~Vector() {
        delete[] data;
    }

    // Метод добавления элемента (Create)
    void add(const T& value) {
        if (size == capacity) {
            resize();
        }
        data[size++] = value;
    }

    // Метод получения элемента (Read)
    T get(size_t index) const {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    // Метод модификации элемента (Update)
    void update(size_t index, const T& value) {
        if (index >= size) throw std::out_of_range("Index out of range");
        data[index] = value;
    }

    // Метод удаления элемента (Delete)
    void remove(size_t index) {
        if (index >= size) throw std::out_of_range("Index out of range");
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }

    // Вывод содержимого в строку
    std::string toString() const {
        std::ostringstream oss;
        for (size_t i = 0; i < size; ++i) {
            oss << data[i] << " ";
        }
        return oss.str();
    }

    // Итератор
    class Iterator {
    private:
        T* ptr;
    public:
        Iterator(T* ptr) : ptr(ptr) {}
        Iterator operator++() { ++ptr; return *this; }
        bool operator!=(const Iterator& other) const { return ptr != other.ptr; }
        T& operator*() const { return *ptr; }
    };

    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + size); }

    // Переопределение операторов сдвига для потокового ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
        for (size_t i = 0; i < vec.size; ++i) {
            os << vec.data[i] << " ";
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Vector<T>& vec) {
        T value;
        while (is >> value) {
            vec.add(value);
        }
        return is;
    }

private:
    // Приватный метод для увеличения вместимости массива
    void resize() {
        capacity *= 2;
        T* new_data = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }
};

#endif // VECTOR_H
