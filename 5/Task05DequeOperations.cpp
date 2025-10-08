#include "Task05DequeOperations.h"

using namespace std;

void DequeOperations::InsertMiddleElements(deque<int>& d) {
    size_t size = d.size();
    if (size < 5 || size % 2 == 0) {
        throw invalid_argument("Дек должен содержать нечетное количество"
                               "элементов (>=5)");
    }

    size_t middle_index = size / 2;
    deque<int>::iterator start = d.begin() + middle_index - 2;
    deque<int>::iterator end = d.begin() + middle_index + 3;

    d.insert(d.begin(), start, end);
}

deque<int> DequeOperations::InputFromKeyboard() {
    int count = 0;
    cout << "Введите количество целых чисел (нечетное и >=5): ";
    cin >> count;

    while (count < 5 || count % 2 == 0) {
        cout << "Количество должно быть нечетным и >=5. Повторите ввод: ";
        cin >> count;
    }

    deque<int> result;
    cout << "Введите " << count << " целых чисел:" << endl;
    for (int i = 0; i < count; ++i) {
        int number = 0;
        cin >> number;
        result.push_back(number);
    }

    return result;
}

deque<int> DequeOperations::GenerateRandom(int count) {
    if (count < 5 || count % 2 == 0) {
        throw invalid_argument("Количество должно быть нечетным и >=5");
    }

    deque<int> result;
    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 0; i < count; ++i) {
        result.push_back(rand() % 100);
    }

    return result;
}

deque<int> DequeOperations::ReadFromFile(const string& filename) {
    ifstream infile(filename);
    if (!infile.is_open()) {
        throw runtime_error("Не удалось открыть файл: " + filename);
    }

    deque<int> result;
    int number;
    while (infile >> number) {
        result.push_back(number);
    }

    if (result.size() < 5 || result.size() % 2 == 0) {
        throw invalid_argument("Файл должен содержать нечетное"
                               "количество чисел (>=5)");
    }

    return result;
}

void DequeOperations::PrintDeque(const deque<int>& d) {
    for (int i : d) {
        cout << i << " ";
    }
    cout << endl;
}
