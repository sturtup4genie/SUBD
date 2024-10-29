#pragma once
#include <iostream>

namespace sphere
{
    /**
    * @brief Класс Шар
    */
    class Sphere
    {
    private:
        /**
        * @brief Радиус
        */
        double radius;

    public:
        /*
        * @brief Вернуть радиус
        * @return Радиус
        */
        double GetRadius() const;

        /*
        * @brief Вернуть диаметр
        * @return Диаметр
        */
        double GetDiameter() const;

        /*
        * @brief Рассчитать площадь поверхности
        * @return Площадь поверхности
        */
        double GetSurfaceArea() const;

        /*
        * @brief Рассчитать объем шара
        * @return Объем шара
        */
        double GetVolume() const;

        /*
        * @brief Инициализировать новый объект класса Sphere
        * @param radius Радиус
        */
        explicit Sphere(const double radius);
    };

    /*
    * @brief Выводит в поток информацию о шаре
    * @param output Поток вывода
    * @param object Шар
    */
    std::ostream& operator<<(std::ostream& output, const Sphere& object);
}
#pragma once
