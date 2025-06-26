/*
 * Элементами контейнеров являются целые числа. Для заполнения контейнера
 * использовать итератор и конструктор соответствующего контейнера, для вывода
 * элементов использовать итератор (для вывода элементов в обратном порядке
 * использовать обратные итераторы, возвращаемые функциями-членами rbegin и
 * rend) Обязательно наличие дружественного интерфейса. Ввод данных организовать
 * разными способами (с клавиатуры, рандом, из файла) Дан дек D с нечетным
 * количеством элементов N (≥ 5). Добавить в начало дека пять его средних
 * элементов в исходном порядке. Использовать один вызов функции-члена insert.
 */
#include "Task05DequeOperations.h"
#include <iostream>

using namespace std;

int main() {
    int choice = 0;
    cout << "Выберите метод ввода данных:\n"
         << "1. Ввод с клавиатуры\n"
         << "2. Случайные числа\n"
         << "3. Чтение из файла\n"
         << "Ваш выбор: ";
    cin >> choice;

    try {
        deque<int> d;

        switch (choice) {
            case 1:
                d = DequeOperations::InputFromKeyboard();
                break;
            case 2: {
                int count = 0;
                cout << "Введите количество чисел (нечетное и >=5): ";
                cin >> count;
                d = DequeOperations::GenerateRandom(count);
                break;
            }
            case 3:
                d = DequeOperations::ReadFromFile("a.txt");
                break;
            default:
                cerr << "Некорректный выбор." << endl;
                return 1;
        }

        cout << "Исходный дек: ";
        DequeOperations::PrintDeque(d);

        DequeOperations::InsertMiddleElements(d);

        cout << "Дек после вставки: ";
        DequeOperations::PrintDeque(d);

    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }

    return 0;
}