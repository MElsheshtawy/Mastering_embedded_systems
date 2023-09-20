#ifndef PROJECT_2_STUDENTDATABASE_H
#define PROJECT_2_STUDENTDATABASE_H
#include "stdio.h"

//Improve Readability
#define erase   fflush(stdout); fflush(stdin);

//functions prototypes
void Add_Student_Manually(); // case 1
void Add_Student_File(); // case 2
void Find_By_Number(); // case 3
void Find_FirstName(); // case 4
void Find_DetByCourses(); // case 5
void Total_Students(); // case 6
void Delete_Student(); // case 7
void Update_Student(); // case 8
void Show_Student(); // case 9

// Student DataType
typedef struct
{
    char FirstName[30];
    char LastName[30];
    int Roll;
    float GPA;
    int CId[5];
}Student;

#endif //PROJECT_2_STUDENTDATABASE_H
