#pragma once
#include <iostream>

namespace sphere
{
    /**
    * @brief Класс Шар
    * 
    * Данный класс представляет собой сферу с заданным радиусом.
    */
    class Sphere
    {
    private:
        /**
        * @brief Радиус
        * 
        * Радиус шара. Должен быть положительным числом.
        */
        double radius;

    public:
        /**
        * @brief Вернуть радиус
        * 
        * @return Радиус шара.
        */
        double GetRadius() const;

        /**
        * @brief Вернуть диаметр
        * 
        * @return Диаметр шара, равный двум радиусам.
        */
        double GetDiameter() const;

        /**
        * @brief Рассчитать площадь поверхности
        * 
        * @return Площадь поверхности шара.
        */
        double GetSurfaceArea() const;

        /**
        * @brief Рассчитать объем шара
        * 
        * @return Объем шара.
        */
        double GetVolume() const;

        /**
        * @brief Инициализировать новый объект класса Sphere
        * 
        * @param radius Радиус шара. Должен быть положительным числом.
        * @throws std::invalid_argument Если радиус не положителен.
        */
        explicit Sphere(const double radius);
    };

    /**
    * @brief Выводит в поток информацию о шаре
    * 
    * Перегрузка оператора вывода для класса Sphere. 
    * 
    * @param output Поток вывода, в который будет записана информация о шаре.
    * @param object Объект Sphere, информация о котором будет выведена.
    * @return Ссылка на поток вывода.
    */
    std::ostream& operator<<(std::ostream& output, const Sphere& object);
}
#pragma once
