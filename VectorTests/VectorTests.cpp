#include "pch.h"
#include "CppUnitTest.h"
#include "Vector.h" // Подключение основного заголовочного файла

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorTests
{
    TEST_CLASS(VectorTests)
    {
    public:
        
        /**
         * @brief Тест на корректность конструктора.
         */
        TEST_METHOD(ConstructorTest)
        {
            Vector vec;
            Assert::IsTrue(true); // Проверка, что объект успешно создается
        }

        /**
         * @brief Тест на добавление элементов в вектор.
         */
        TEST_METHOD(AddElementTest)
        {
            Vector vec;
            vec.add(10);
            Assert::AreEqual(vec.get(0), 10);
        }

        /**
         * @brief Тест на получение элемента по индексу.
         */
        TEST_METHOD(GetElementTest)
        {
            Vector vec;
            vec.add(5);
            vec.add(15);
            Assert::AreEqual(vec.get(0), 5);
            Assert::AreEqual(vec.get(1), 15);
        }

        /**
         * @brief Тест на исключение при выходе за пределы массива.
         */
        TEST_METHOD(OutOfRangeTest)
        {
            Vector vec;
            try {
                vec.get(100);
                Assert::Fail(L"Ожидалось исключение std::out_of_range.");
            }
            catch (const std::out_of_range&) {
                Assert::IsTrue(true);
            }
        }

        /**
         * @brief Тест на обновление элемента по индексу.
         */
        TEST_METHOD(UpdateElementTest)
        {
            Vector vec;
            vec.add(10);
            vec.update(0, 20);
            Assert::AreEqual(vec.get(0), 20);
        }

        /**
         * @brief Тест на удаление элемента.
         */
        TEST_METHOD(RemoveElementTest)
        {
            Vector vec;
            vec.add(10);
            vec.add(20);
            vec.remove(0);
            Assert::AreEqual(vec.get(0), 20);
        }

        /**
         * @brief Тест на корректное увеличение размера массива.
         */
        TEST_METHOD(ResizeTest)
        {
            Vector vec;
            for (int i = 0; i < 15; ++i) {
                vec.add(i);
            }
            Assert::AreEqual(vec.get(14), 14);
        }

        /**
         * @brief Тест на преобразование вектора в строку.
         */
        TEST_METHOD(ToStringTest)
        {
            Vector vec;
            vec.add(1);
            vec.add(2);
            vec.add(3);
            Assert::AreEqual(vec.toString(), std::string("1 2 3 "));
        }
    };
}
