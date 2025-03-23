#pragma once


using namespace std;

class Sort
{
private:
    int* elements;
    int size;

    void QuickSortHelper(int left, int right, bool ascendent);

public:
    // Constructors
    Sort(int count, int min, int max);                   // Random
    Sort(int count,int *arr);            // Init list
    Sort(int* arr, int count);                           // From array
    Sort(int count, ...);                                // Variadic
    Sort(const char* numbers);                           // From string

    // Destructor
    ~Sort();

    // Sorting algorithms
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);

    // Utility methods
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};
