#ifndef LAB2_TASK05DEQUEOPERATIONS_H
#define LAB2_TASK05DEQUEOPERATIONS_H

#include <deque>
#include <string>

class DequeOperations {
public:
    static void InsertMiddleElements(std::deque<int>& d);
    static std::deque<int> InputFromKeyboard();
    static std::deque<int> GenerateRandom(int count);
    static std::deque<int> ReadFromFile(const std::string& filename);
    static void PrintDeque(const std::deque<int>& d);
};

#endif //LAB2_TASK05DEQUEOPERATIONS_H
