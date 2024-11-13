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

        std::cout << "������� ������ ����: ";
        std::cin >> radius;

        Sphere first(radius);

        std::cout << "��������� ������: " << first.GetRadius() << "\n";
        std::cout << "������� ����: " << first.GetDiameter() << "\n";
        std::cout << "������� ����������� ����: " << first.GetSurfaceArea() << "\n";
        std::cout << "����� ����: " << first.GetVolume() << "\n";

        std::cout << "\n ������������ ���������� ��������� ������ � �����:\n";
        std::cout << first << "\n";

        return 0;
    }
    catch (const std::exception& error)
    {
        std::cout << "������: " << error.what() << "\n";
    }

    return -1;
}
