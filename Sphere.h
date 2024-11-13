#pragma once
#include <iostream>

namespace sphere
{
    /**
    * @brief ����� ���
    */
    class Sphere
    {
    private:
        /**
        * @brief ������
        */
        double radius;

    public:
        /*
        * @brief ������� ������
        * @return ������
        */
        double GetRadius() const;

        /*
        * @brief ������� �������
        * @return �������
        */
        double GetDiameter() const;

        /*
        * @brief ���������� ������� �����������
        * @return ������� �����������
        */
        double GetSurfaceArea() const;

        /*
        * @brief ���������� ����� ����
        * @return ����� ����
        */
        double GetVolume() const;

        /*
        * @brief ���������������� ����� ������ ������ Sphere
        * @param radius ������
        */
        explicit Sphere(const double radius);
    };

    /*
    * @brief ������� � ����� ���������� � ����
    * @param output ����� ������
    * @param object ���
    */
    std::ostream& operator<<(std::ostream& output, const Sphere& object);
}
#pragma once
