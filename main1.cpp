#include <iostream>
#include "NumberList.h"
#include "NumberList.cpp"

int main() {
    NumberList list;
    list.Init();

    // Adding numbers
    list.Add(5);
    list.Add(3);
    list.Add(8);
    list.Add(1);
    list.Add(4);

    std::cout << "Unsorted list: ";
    list.Print();

    // Sorting numbers
    list.Sort();
    std::cout << "Sorted list: ";
    list.Print();


    return 0;
}
