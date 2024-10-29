#include <iostream>
#include <clocale>

#include "Sphere.h"
#include "Sphere.cpp"


int main()
{
    setlocale(LC_ALL, "RUS");

    using namespace sphere;

    try
    {
        double radius;

        std::cout << "Введите радиус шара: ";
        std::cin >> radius;

        Sphere first(radius);

        std::cout << "Введенный радиус: " << first.GetRadius() << "\n";
        std::cout << "Диаметр шара: " << first.GetDiameter() << "\n";
        std::cout << "Площадь поверхности шара: " << first.GetSurfaceArea() << "\n";
        std::cout << "Объем шара: " << first.GetVolume() << "\n";

        std::cout << "\n Демонстрация перегрузки оператора вывода в поток:\n";
        std::cout << first << "\n";

        return 0;
    }
    catch (const std::exception& error)
    {
        std::cout << "ОШИБКА: " << error.what() << "\n";
    }

    return -1;
}
