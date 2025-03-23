#include <iostream>
#include "sort.h"
#include "sort.cpp"
using namespace std;

int main()
{
    int vec[] = { 7, 2, 8,2 };
    // Random
    Sort s1(5, 10, 50);
    cout << "Random: ";
    s1.Print();
    s1.InsertSort(true);
    cout << "Sorted (InsertSort, Asc): ";
    s1.Print();

    Sort s2(4, vec); 
    cout << "\nInit List: ";
    s2.Print(); 
    s2.BubbleSort(false);
    cout << "Sorted (BubbleSort, Desc): ";
    s2.Print();

    
    // From array
    int arr[] = { 7, 2, 8, 1, 9 };
    Sort s3(arr, 5);
    cout << "\nFrom Array: ";
    s3.Print();
    s3.QuickSort(true);
    cout << "Sorted (QuickSort, Asc): ";
    s3.Print();

    // Variadic
    Sort s4(4, 100, 20, 40, 10);
    cout << "\nVariadic: ";
    s4.Print();
    s4.InsertSort(false);
    cout << "Sorted (InsertSort, Desc): ";
    s4.Print();

    // From string
    Sort s5("10,3,25,8,60");
    cout << "\nFrom String: ";
    s5.Print();
    s5.BubbleSort(true);
    cout << "Sorted (BubbleSort, Asc): ";
    s5.Print();

    cout << "\nElement at index 2 in s5: " << s5.GetElementFromIndex(2) << '\n';
    cout << "Number of elements in s5: " << s5.GetElementsCount() << '\n';

    return 0;
}
