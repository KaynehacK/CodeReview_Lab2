/*
 * Все динамические структуры данных реализовывать через классы. Не использовать
 * STL. Для каждой динамической структуры должен быть предусмотрен стандартный
 * набор методов - добавления/удаления/вывода элементов. Во всех задачах
 * обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.
 *
 *  Дан односвязный линейный список и указатель на голову списка P1. Необходимо
 * вставить значение M перед каждым вторым элементом списка, и вывести ссылку на
 * последний элемент полученного списка P2. При нечетном числе элементов
 * исходного списка в конец списка вставлять не надо.
*/

#include "Task03LinkedList.h"
#include <iostream>

using namespace std;

int main() {
    LinkedList list;
    int num_elements = 0;
    int element_value = 0;
    int m_value = 0;

    cout << "Введите количество элементов в списке: ";
    cin >> num_elements;

    cout << "Введите элементы списка: ";
    for (int i = 0; i < num_elements; ++i) {
        cin >> element_value;
        list.AddElement(element_value);
    }

    cout << "Введите значение M для вставки: ";
    cin >> m_value;

    list.InsertBeforeEverySecond(m_value);

    cout << "Список после вставки: ";
    list.PrintList();

    Node* last_node = list.GetLastNode();
    if (last_node != nullptr) {
        cout << "Указатель на последний элемент списка: "
             << last_node << endl;
        cout << "Значение последнего элемента: "
             << last_node->get_data() << endl;
    } else {
        cout << "Список пуст." << endl;
    }

    list.ClearList();
    cout << "Проверка списка после очистки: ";
    list.PrintList();

    return 0;
}