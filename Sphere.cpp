#include <stdexcept>
#include <cmath>

#include "Sphere.h"

double sphere::Sphere::GetRadius() const
{
    return radius;
}

double sphere::Sphere::GetDiameter() const
{
    return 2 * radius;
}

double sphere::Sphere::GetSurfaceArea() const
{
    const double PI = 3.1415926535;
    return 4 * PI * std::pow(radius, 2);
}

double sphere::Sphere::GetVolume() const
{
    const double PI = 3.1415926535;
    return (4.0 / 3.0) * PI * std::pow(radius, 3);
}

sphere::Sphere::Sphere(const double radius)
{
    if (radius <= 0)
    {
        throw std::invalid_argument("������ ������ ���� ������������� ������.");
    }
    this->radius = radius;
}

std::ostream& sphere::operator<<(std::ostream& output, const Sphere& object)
{
    output << "������ ����: " << object.GetRadius() << "\n";
    output << "������� ����: " << object.GetDiameter() << "\n";
    output << "������� ����������� ����: " << object.GetSurfaceArea() << "\n";
    output << "����� ����: " << object.GetVolume() << "\n";

    return output;
}
