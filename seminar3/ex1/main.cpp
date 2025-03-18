#include <iostream>
#include "math.h"
#include "math.cpp"
using namespace std;

int main() {
    cout << "Add(int, int): " << Math::Add(3, 4) << "\n";
    cout << "Add(int, int, int): " << Math::Add(1, 2, 3) << "\n";
    cout << "Add(double, double): " << Math::Add(2.5, 3.5) << "\n";
    cout << "Add(double, double, double): " << Math::Add(1.1, 2.2, 3.3) << "\n";

    cout << "Mul(int, int): " << Math::Mul(2, 3) << "\n";
    cout << "Mul(int, int, int): " << Math::Mul(2, 3, 4) << "\n";
    cout << "Mul(double, double): " << Math::Mul(2.5, 4.0) << "\n";
    cout << "Mul(double, double, double): " << Math::Mul(1.5, 2.0, 3.0) << "\n";

    cout << "Add(int count, ...): " << Math::Add(5, 1, 2, 3, 4, 5) << "\n";

    const char* str1 = "Hello, ";
    const char* str2 = "world!";
    char* result = Math::Add(str1, str2);

    if (result) {
        cout << "Add(const char*, const char*): " << result << "\n";
        delete[] result; 
    } else {
        cout << "String Add returned nullptr.\n";
    }

    return 0;
}
