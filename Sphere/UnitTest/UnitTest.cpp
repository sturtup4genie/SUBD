#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include "CppUnitTest.h"

#include "..\Domain\Sphere.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(SphereTests)
    {
    public:
        TEST_METHOD(Constructor_NegativeRadius_ExpectedException)
        {
            // Assert
            Assert::ExpectException<std::invalid_argument>([]() { sphere::Sphere obj(-5.0); });
        }

        TEST_METHOD(GetRadius_ValidData_Success)
        {
            // Arrange
            const double R = 3.0;
            sphere::Sphere obj{ R };
            const double expected = R;
            const double epsilon = 0.001;

            // Act
            const double actual = obj.GetRadius();

            // Assert
            Assert::IsTrue(std::abs(expected - actual) <= epsilon);
        }

        TEST_METHOD(GetDiameter_ValidData_Success)
        {
            // Arrange
            const double R = 3.0;
            sphere::Sphere obj{ R };
            const double expected = R * 2;
            const double epsilon = 0.001;

            // Act
            const double actual = obj.GetDiameter();

            // Assert
            Assert::IsTrue(std::abs(expected - actual) <= epsilon);
        }

        TEST_METHOD(GetSurfaceArea_ValidData_Success)
        {
            // Arrange
            const double R = 3.0;
            sphere::Sphere obj{ R };
            auto expected = 4 * M_PI * R * R;
            const double epsilon = 0.001;

            // Act
            auto actual = obj.GetSurfaceArea();

            // Assert
            Assert::IsTrue(std::abs(expected - actual) <= epsilon);
        }

        TEST_METHOD(GetVolume_ValidData_Success)
        {
            // Arrange
            const double R = 3.0;
            sphere::Sphere obj{ R };
            auto expected = (4.0 / 3.0) * M_PI * R * R * R;
            const double epsilon = 0.001;

            // Act
            auto actual = obj.GetVolume();

            // Assert
            Assert::IsTrue(std::abs(expected - actual) <= epsilon);
        }

        TEST_METHOD(OperatorLeftShift_ValidData_Success)
        {
            // Arrange
            const double R = 3.0;
            sphere::Sphere obj{ R };
            std::stringstream buffer{};
            const std::string expected =
                "Радиус шара: " + std::to_string(obj.GetRadius()) + "\n" +
                "Диаметр шара: " + std::to_string(obj.GetDiameter()) + "\n" +
                "Площадь поверхности шара: " + std::to_string(obj.GetSurfaceArea()) + "\n" +
                "Объем шара: " + std::to_string(obj.GetVolume()) + "\n";

            // Act
            buffer << std::fixed << obj;
            std::string actual = buffer.str();

            // Assert
            Assert::AreEqual(expected, actual);
        }
    };
}
