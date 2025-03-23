#include "sort.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdarg>
#include <cstring>

using namespace std;

// Constructor: random values
Sort::Sort(int count, int min, int max)
{
    srand((unsigned)time(nullptr));
    size = count;
    elements = new int[size];
    for (int i = 0; i < size; ++i)
        elements[i] = min + rand() % (max - min + 1);
}

Sort::Sort(int count,int *arr):elements(new int[count]), size(count){
        for(int i=0;i<count;i++)
            elements[i]=arr[i];
    }            // Init list

// Constructor: from array
Sort::Sort(int* arr, int count)
{
    size = count;
    elements = new int[size];
    for (int i = 0; i < size; ++i)
        elements[i] = arr[i];
}

// Constructor: variadic
Sort::Sort(int count, ...)
{
    size = count;
    elements = new int[size];
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i)
        elements[i] = va_arg(args, int);
    va_end(args);
}

// Constructor: from comma-separated C-string
Sort::Sort(const char* numbers)
{
    size = 1;
    for (int i = 0; numbers[i]; ++i)
        if (numbers[i] == ',')
            ++size;

    elements = new int[size];
    int index = 0;
    const char* p = numbers;
    while (*p)
    {
        int value = 0;
        while (*p >= '0' && *p <= '9')
        {
            value = value * 10 + (*p - '0');
            ++p;
        }
        elements[index++] = value;
        if (*p == ',')
            ++p;
    }
}

// Destructor
Sort::~Sort()
{
    delete[] elements;
}

// Insertion Sort
void Sort::InsertSort(bool ascendent)
{
    for (int i = 1; i < size; ++i)
    {
        int key = elements[i];
        int j = i - 1;
        while (j >= 0 && (ascendent ? elements[j] > key : elements[j] < key))
        {
            elements[j + 1] = elements[j];
            --j;
        }
        elements[j + 1] = key;
    }
}

// Bubble Sort
void Sort::BubbleSort(bool ascendent)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if ((ascendent && elements[j] > elements[j + 1]) || (!ascendent && elements[j] < elements[j + 1]))
            {
                int temp = elements[j];
                elements[j] = elements[j + 1];
                elements[j + 1] = temp;
            }
        }
    }
}

// QuickSort helper
void Sort::QuickSortHelper(int left, int right, bool ascendent)
{
    if (left >= right)
        return;

    int pivot = elements[right];
    int i = left - 1;

    for (int j = left; j < right; ++j)
    {
        if ((ascendent && elements[j] <= pivot) || (!ascendent && elements[j] >= pivot))
        {
            ++i;
            int temp = elements[i];
            elements[i] = elements[j];
            elements[j] = temp;
        }
    }
    int temp = elements[i + 1];
    elements[i + 1] = elements[right];
    elements[right] = temp;

    QuickSortHelper(left, i, ascendent);
    QuickSortHelper(i + 2, right, ascendent);
}

// QuickSort public
void Sort::QuickSort(bool ascendent)
{
    QuickSortHelper(0, size - 1, ascendent);
}

// Utility methods
void Sort::Print()
{
    for (int i = 0; i < size; ++i)
        cout << elements[i] << ' ';
    cout << '\n';
}

int Sort::GetElementsCount()
{
    return size;
}

int Sort::GetElementFromIndex(int index)
{
    if (index >= 0 && index < size)
        return elements[index];
    return -1;
}
