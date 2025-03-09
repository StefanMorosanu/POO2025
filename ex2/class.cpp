#include "class.h"
#include <string.h>

void Student::SetName(char* studentName) {
   strcpy (this-> name ,studentName);
}

char* Student::GetName(){
    return this-> name;
}

void Student::SetMathGrade(float grade) {
    this->mathGrade = grade;
}

float Student::GetMathGrade() {
    return mathGrade;
}

void Student::SetEnglishGrade(float grade) {
    this-> englishGrade = grade;
}

float Student::GetEnglishGrade() {
    return englishGrade;
}

void Student::SetHistoryGrade(float grade) {
  this-> historyGrade = grade;
}

float Student::GetHistoryGrade() {
    return historyGrade;
}

float Student::GetAverage() {
    return (mathGrade + englishGrade + historyGrade) / 3.0f;
}

