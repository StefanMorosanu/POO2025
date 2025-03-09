#include <iostream>
#include "class.h"
#include "compare.h"
#include "class.cpp"
#include "compare.cpp"
using namespace std;
int main() 
{
    Student s1;
    s1.SetName((char*)"Ion");
    s1.SetMathGrade(9);
    s1.SetEnglishGrade(8);
    s1.SetHistoryGrade(7);
    Student s2;
    s2.SetName((char*)"Vasile");
    s2.SetMathGrade(7);
    s2.SetEnglishGrade(8);
    s2.SetHistoryGrade(9);
    cout << "CompareByName: " << CompareByName(&s1, &s2) << endl;
    cout << "CompareByMathGrade: " << CompareByMathGrade(&s1, &s2) << endl;
    cout << "CompareByEnglishGrade: " << CompareByEnglishGrade(&s1, &s2) << endl;
    cout << "CompareByHistoryGrade: " << CompareByHistoryGrade(&s1, &s2) << endl;
    cout << "CompareByAverageGrade: " << CompareByAverageGrade(&s1, &s2) << endl;
    return 0;
}
