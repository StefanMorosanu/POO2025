#pragma once
#include <string>

class Student {
private:
    char name[50];
    float mathGrade;
    float englishGrade;
    float historyGrade;

public:
    // Name
    void SetName(char* nume);
     char* GetName();

    // Grades
    void SetMathGrade(float grade);
    float GetMathGrade() ;

    void SetEnglishGrade(float grade);
    float GetEnglishGrade();

    void SetHistoryGrade(float grade);
    float GetHistoryGrade();

    // Average
    float GetAverage();
};
