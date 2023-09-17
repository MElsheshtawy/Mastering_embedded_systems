#ifndef LINKED_LIST_LINKED_LIST_H
#define LINKED_LIST_LINKED_LIST_H
#include "stdint.h"
#include "stdio.h"

#define Dprintf(...) fflush(stdin);fflush(stdout);printf(__VA_ARGS__);fflush(stdin);fflush(stdout)

typedef struct SStudent SStudent;
struct SStudent
{
    struct
    {
        uint8_t S_Name[40];
        uint32_t ID;
        float Height;
    }Student_Info;
    SStudent * PNextStudent;
};
void Fill_Student_Info (SStudent *Student);
void Add_Student ();
void Remove_Student();
void GetNth(uint32_t Index);
void GetNth_From_End(uint32_t Index);
void Get_Middle();
void List_Reverse();
void View_Students();
void Delete_All();
uint32_t List_Length_Iterative(SStudent* GP);
#endif //LINKED_LIST_LINKED_LIST_H
