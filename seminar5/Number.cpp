#include "Number.h"

using namespace std;


Number::Number(const char* val, int b) : base(b) {
    value = new char[strlen(val) + 1];
    strcpy(value, val);
}


Number::Number(const Number& other) {
    base = other.base;
    value = new char[strlen(other.value) + 1];
    strcpy(value, other.value);
}


Number& Number::operator=(const Number& other) {
    if (this == &other) return *this;  

    delete[] value;
    base = other.base;
    value = new char[strlen(other.value) + 1];
    strcpy(value, other.value);
    return *this;
}


Number::~Number() {
    delete[] value;
}


int ToDecimal(const char* val, int base) {
    int result = 0;
    for (int i = 0; val[i] != '\0'; i++) {
        char digit = val[i];
        int num = (digit >= '0' && digit <= '9') ? digit - '0' : digit - 'A' + 10;
        result = result * base + num;
    }
    return result;
}


void FromDecimal(int num, int base, char* out) {
    char temp[50];
    int index = 0;
    
    while (num > 0) {
        int remainder = num % base;
        temp[index++] = (remainder < 10) ? ('0' + remainder) : ('A' + remainder - 10);
        num /= base;
    }
    
   
    for (int i = 0; i < index; i++) {
        out[i] = temp[index - i - 1];
    }
    out[index] = '\0';
}


void Number::SwitchBase(int newBase) {
    int decimal = ToDecimal(value, base);
    delete[] value;
    value = new char[50];
    FromDecimal(decimal, newBase, value);
    base = newBase;
}


void Number::Print() const {
    cout << value << " (base " << base << ")" << endl;
}


int Number::GetDigitsCount() const {
    return strlen(value);
}


int Number::GetBase() const {
    return base;
}


Number operator+(const Number& a, const Number& b) {
    int dec1 = ToDecimal(a.value, a.base);
    int dec2 = ToDecimal(b.value, b.base);
    int sum = dec1 + dec2;

    int maxBase = (a.base > b.base) ? a.base : b.base;
    char result[50];
    FromDecimal(sum, maxBase, result);

    return Number(result, maxBase);
}


Number operator-(const Number& a, const Number& b) {
    int dec1 = ToDecimal(a.value, a.base);
    int dec2 = ToDecimal(b.value, b.base);
    int diff = dec1 - dec2;

    int maxBase = (a.base > b.base) ? a.base : b.base;
    char result[50];
    FromDecimal(diff, maxBase, result);

    return Number(result, maxBase);
}


char Number::operator[](int index) const {
    return value[index];
}


bool Number::operator==(const Number& other) const {
    return ToDecimal(value, base) == ToDecimal(other.value, other.base);
}


bool Number::operator<(const Number& other) const {
    return ToDecimal(value, base) < ToDecimal(other.value, other.base);
}


bool Number::operator>(const Number& other) const {
    return ToDecimal(value, base) > ToDecimal(other.value, other.base);
}


Number& Number::operator--() {
    memmove(value, value + 1, strlen(value)); 
    return *this;
}

Number Number::operator--(int) {
    Number temp(*this);
    value[strlen(value) - 1] = '\0'; 
    return temp;
}


Number::Number(int val) {
    base = 10;
    value = new char[50];
    FromDecimal(val, base, value);
}


Number& Number::operator=(int val) {
    delete[] value;
    value = new char[50];
    FromDecimal(val, base, value);
    return *this;
}


Number& Number::operator=(const char* val) {
    delete[] value;
    value = new char[strlen(val) + 1];
    strcpy(value, val);
    return *this;
}


Number& Number::operator+=(const Number& other) {
    *this = *this + other;
    return *this;
}
