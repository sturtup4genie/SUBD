#pragma once
#include <iostream>

namespace sphere
{
    /**
    * @brief ����� ���
    *
    * ������ ����� ������������ ����� ����� � �������� ��������.
    */
    class Sphere
    {
    private:
        /**
        * @brief ������
        *
        * ������ ����. ������ ���� ������������� ������.
        */
        double radius;

    public:
        /**
        * @brief ������� ������
        *
        * @return ������ ����.
        */
        double GetRadius() const;

        /**
        * @brief ������� �������
        *
        * @return ������� ����, ������ ���� ��������.
        */
        double GetDiameter() const;

        /**
        * @brief ���������� ������� �����������
        *
        * @return ������� ����������� ����.
        */
        double GetSurfaceArea() const;

        /**
        * @brief ���������� ����� ����
        *
        * @return ����� ����.
        */
        double GetVolume() const;

        /**
        * @brief ���������������� ����� ������ ������ Sphere
        *
        * @param radius ������ ����. ������ ���� ������������� ������.
        * @throws std::invalid_argument ���� ������ �� �����������.
        */
        explicit Sphere(const double radius);
    };

    /**
    * @brief ������� � ����� ���������� � ����
    *
    * ���������� ��������� ������ ��� ������ Sphere.
    *
    * @param output ����� ������, � ������� ����� �������� ���������� � ����.
    * @param object ������ Sphere, ���������� � ������� ����� ��������.
    * @return ������ �� ����� ������.
    */
    std::ostream& operator<<(std::ostream& output, const Sphere& object);
}
#pragma once