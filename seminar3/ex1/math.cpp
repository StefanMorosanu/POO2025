#include "math.h"
#include <cstdarg> 
#include <cstring> 
#include <cstdlib> 
#include <iostream>
int Math::Add(int a, int b) {
    return a + b;
}

int Math::Add(int a, int b, int c) {
    return a + b + c;
}

double Math::Add(double a, double b) {
    return (double)(a + b);
}

double Math::Add(double a, double b, double c) {
    return (double)(a + b + c);
}

int Math::Mul(int a, int b) {
    return a * b;
}

int Math::Mul(int a, int b, int c) {
    return a * b * c;
}

double Math::Mul(double a, double b) {
    return (double)(a * b);
}

double Math::Mul(double a, double b, double c) {
    return (double)(a * b * c);
}

int Math::Add(int count, ...) {
    int sum = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        sum += va_arg(args, int);
    }
    va_end(args);
    return sum;
}

char* Math::Add(const char* str1, const char* str2) {
    if (str1 == nullptr || str2 == nullptr) {
        return nullptr;
    }

    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char* result = new char[len1 + len2 + 1];

    if (result) {
        strcpy(result, str1);
        strcat(result, str2);
    }

    return result;
}
