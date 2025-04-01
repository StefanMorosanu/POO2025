#pragma once
#include <iostream>
#include <cstring>
#include <cmath>

class Number
{
private:
    char* value;
    int base;

public:
    // Constructori
    Number(const char* val, int base);
    Number(int val);
    Number(const Number& other);    // Copy constructor
    Number& operator=(const Number& other); // Copy assignment
    ~Number();

    // Metode
    void SwitchBase(int newBase);
    void Print() const;
    int GetDigitsCount() const;
    int GetBase() const;

    // Operatorii ceruți
    friend Number operator+(const Number& a, const Number& b);
    friend Number operator-(const Number& a, const Number& b);
    char operator[](int index) const;
    bool operator>(const Number& other) const;
    bool operator<(const Number& other) const;
    bool operator>=(const Number& other) const;
    bool operator<=(const Number& other) const;
    bool operator==(const Number& other) const;
    bool operator!=(const Number& other) const;

    Number& operator=(int val);
    Number& operator=(const char* val);
    Number& operator+=(const Number& other);

    // Operator -- (prefix și postfix)
    Number& operator--();    // Prefix
    Number operator--(int);  // Postfix
};


