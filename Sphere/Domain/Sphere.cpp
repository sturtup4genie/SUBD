#define _USE_MATH_DEFINES // for C++
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
    return 4 * M_PI * std::pow(radius, 2);
}

double sphere::Sphere::GetVolume() const
{
    return (4.0 / 3.0) * M_PI * std::pow(radius, 3);
}

sphere::Sphere::Sphere(const double radius)
{
    if (radius <= 0)
    {
        throw std::invalid_argument("Радиус должен быть положительным числом.");
    }
    this->radius = radius;
}

std::ostream& sphere::operator<<(std::ostream& output, const Sphere& object)
{
    output << "Радиус шара: " << object.GetRadius() << "\n";
    output << "Диаметр шара: " << object.GetDiameter() << "\n";
    output << "Площадь поверхности шара: " << object.GetSurfaceArea() << "\n";
    output << "Объем шара: " << object.GetVolume() << "\n";

    return output;
}
