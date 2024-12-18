#include "pch.h"
#include "Stack.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace stack;

namespace UnitTest {
    TEST_CLASS(StackTest) {
    public:
        // Тест: Добавление элементов и проверка top()
        TEST_METHOD(PushAndTopTest) {
            Stack stack;
            stack.push(10);
            stack.push(20);
            Assert::AreEqual(20, stack.top());
        }

        // Тест: Удаление верхнего элемента
        TEST_METHOD(PopTest) {
            Stack stack;
            stack.push(10);
            stack.push(20);
            stack.pop();
            Assert::AreEqual(10, stack.top());
        }

        // Тест: Проверка пустого стека
        TEST_METHOD(IsEmptyTest) {
            Stack stack;
            Assert::IsTrue(stack.isEmpty());
            stack.push(10);
            Assert::IsFalse(stack.isEmpty());
        }

        // Тест: Исключение при удалении из пустого стека
        TEST_METHOD(PopEmptyStackTest) {
            Stack stack;
            Assert::ExpectException<std::runtime_error>([&stack]() { stack.pop(); },
                L"Ожидается исключение при удалении из пустого стека.");
        }

        // Тест: Преобразование стека в строку
        TEST_METHOD(ToStringTest) {
            Stack stack;
            stack.push(1);
            stack.push(2);
            stack.push(3);
            Assert::AreEqual(std::string("1 2 3 "), stack.toString());
        }
    };
}
