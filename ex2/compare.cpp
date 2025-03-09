#include "compare.h"
#include <string.h>

int CompareByName( Student* s1,  Student* s2) {
    if (strcmp(s1->GetName(),s2->GetName())==0) return 0;
    if (strcmp (s1->GetName(),s2->GetName())==1) return 1;
    else return -1;
}

int CompareByMathGrade( Student* s1, Student* s2) {
    if (s1->GetMathGrade() == s2->GetMathGrade()) return 0;
    if (s1->GetMathGrade() > s2->GetMathGrade()) return 1;
    else return -1;
}

int CompareByEnglishGrade( Student* s1, Student* s2) {
    if (s1->GetEnglishGrade() == s2->GetEnglishGrade()) return 0;
    if (s1->GetEnglishGrade() > s2->GetEnglishGrade()) return 1;
    else return -1;
}

int CompareByHistoryGrade( Student* s1,Student* s2) {
    if (s1->GetHistoryGrade() == s2->GetHistoryGrade()) return 0;
    if (s1->GetHistoryGrade() > s2->GetHistoryGrade())return 1;
    else return -1;
}

int CompareByAverageGrade( Student* s1,  Student* s2) {
    if (s1->GetAverage() == s2->GetAverage()) return 0;
    if (s1->GetAverage() > s2->GetAverage()) return 1;
    else return -1;
}
