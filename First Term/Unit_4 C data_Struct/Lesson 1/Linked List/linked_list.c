#include "linked_list.h"
#include <stdlib.h>

extern SStudent * gpFirstStudent;

void Fill_Student_Info (SStudent *Student) {
    uint8_t temp[40];
    Dprintf("Enter Student Name : ");
    fgets(Student->Student_Info.S_Name, sizeof(Student->Student_Info.S_Name), stdin);
    Dprintf("Enter Student ID : ");
    scanf("%d",&(Student->Student_Info.ID));
    Dprintf("Enter Student Height : ");
    scanf("%g",&(Student->Student_Info.Height));
}
void Add_Student ()
{
    SStudent * Student = (SStudent *)malloc(sizeof(SStudent));
    SStudent * CurrentStudent =gpFirstStudent;
    if(!gpFirstStudent)
    {
        gpFirstStudent = Student;
    }
    else
    {
        while(CurrentStudent->PNextStudent)
        {
            CurrentStudent = CurrentStudent->PNextStudent;
        }
        CurrentStudent->PNextStudent = Student;
    }
    Student->PNextStudent = NULL;
    Fill_Student_Info(Student);
}
void Remove_Student(){
    SStudent *studentremove,*prevstudent;
    if(!gpFirstStudent){
        Dprintf("There is no students left");
        return;
    }
    int ID;
    Dprintf("Enter Student ID: ");
    scanf("%d",&ID);
    studentremove = gpFirstStudent;
    while(studentremove){
        if(studentremove->Student_Info.ID == ID){
            if(!prevstudent){
                gpFirstStudent= studentremove->PNextStudent;
            }
            else
            {
                prevstudent->PNextStudent = studentremove->PNextStudent;
            }
            Dprintf("Student with ID %d is removed\n",ID);
            free(studentremove);
            return;
        }
        prevstudent=studentremove;
        studentremove= studentremove->PNextStudent;
    }
    Dprintf("Error didn't find this ID");
}
uint32_t List_Length_Iterative(SStudent* GP)
{
    uint32_t Counter = 0;
    SStudent * Position = GP;
    while(Position)
    {
        Counter++;
        Position = Position->PNextStudent;
    }
    return Counter;
}
void GetNth_From_End(uint32_t Index)
{
    uint32_t temp = List_Length_Iterative();
    if(Index >temp){
        Dprintf("Index is out of bounds");
        return;
    }
    else{
        temp = temp - Index; //Index from The start
        GetNth(temp);
    }
}
void Get_Middle()
{
    uint32_t temp = List_Length_Iterative();
    if(temp==1)
        GetNth(temp);
    else if(temp == 0){
        Dprintf("List is Empty");
    }
    else{
        GetNth(temp>>1);
    }
}
void GetNth(uint32_t Index)
{
    SStudent * Position = gpFirstStudent;
    uint32_t i=0;
    if(!gpFirstStudent)
        printf("Error : List is Empty !!\n");
    else
    {
        for(; i<Index ; i++)
            Position=Position->PNextStudent;
        Dprintf("Student Found Successfully :\n");
        Dprintf("Student Name  : %sStudent ID : %d\nStudent Height %f\n",Position->Student_Info.S_Name , Position ->Student_Info.ID , Position ->Student_Info.Height);
    }
}
void List_Reverse()
{
    if(!gpFirstStudent || !gpFirstStudent->PNextStudent)
    {
        printf("Error : Nothing To Reverse or There's only one Student in the list\n");
        return;
    }
    SStudent *thirdnode,*secondnode,*firstnode;
    secondnode=firstnode->PNextStudent;thirdnode=secondnode->PNextStudent;firstnode->PNextStudent=NULL;
    while(thirdnode){
        if(!thirdnode->PNextStudent){
            gpFirstStudent=thirdnode;
        }
        SStudent *temp=thirdnode->PNextStudent;
        secondnode->PNextStudent=firstnode;
        thirdnode->PNextStudent=secondnode;
        secondnode=temp;
        thirdnode=secondnode->PNextStudent;
    }
    thirdnode = secondnode;
    secondnode->PNextStudent=firstnode;
    printf("The list is Reversed Successfuly !\n");
}
void Delete_All()
{
    SStudent * Current_Student = gpFirstStudent , *Remove_Student = gpFirstStudent;
    if(!Current_Student)
    {
        printf("List Is Already Empty !!\n");
        return;
    }
    gpFirstStudent = NULL;
    while(Current_Student)
    {
        Current_Student=Current_Student->PNextStudent;
        free(Remove_Student);
        Remove_Student = Current_Student;
    }
    printf("List Deleted !!\n");
}
void View_Students()
{
    uint32_t counter = 1;
    SStudent * Current_Student = gpFirstStudent;
    if(!Current_Student)
    {
        Dprintf("List Is Empty !!\n");
    }
    else
    {
        while(Current_Student)
        {
            Dprintf("Student Number %d :\n",counter);
            Dprintf("Student Name  : %sStudent ID : %d\nStudent Height %f\n",Current_Student->Student_Info.S_Name , Current_Student ->Student_Info.ID , Current_Student ->Student_Info.Height);
            Dprintf("---------------------------------------------\n");
            Current_Student = Current_Student->PNextStudent;
            counter++;
        }
    }
}