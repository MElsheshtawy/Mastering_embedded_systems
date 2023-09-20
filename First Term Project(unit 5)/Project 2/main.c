#include "StudentDatabase.h"
Student Database[50]; // Database
int h =1; // for breaking out
int main()
{
    while(1)
    {
        // Display
        int num;
        printf("\n------------------\n");
        printf("Choose the task you want to perform:\n");
        printf("1. Add a student details manually.\n");
        printf("2. Add student details from text file.\n");
        printf("3. Find student details by roll number.\n");
        printf("4. Find student details by first name.\n");
        printf("5. Find student details by course ID.\n");
        printf("6. Find the total number of students.\n");
        printf("7. Delete student details by roll number.\n");
        printf("8. Update student details by roll number. \n");
        printf("9. Show all information.\n");
        printf("0. to exit.\n");
        printf("\nEnter your choice to perform the task: ");
        erase
        scanf("%d", &num);

        // Program
        switch(num)
        {
            case 1:
                Add_Student_Manually();
                break;

            case 2:
                Add_Student_File();
                break;

            case 3:
                Find_By_Number();
                break;

            case 4:
                Find_FirstName();
                break;

            case 5:
                Find_DetByCourses();
                break;

            case 6:
                Total_Students();
                break;

            case 7:
                Delete_Student();
                break;

            case 8:
                Update_Student();
                break;


            case 9:
                Show_Student();
                break;

            case 0:
                h=0;
                break;
            default:
                printf("\n---------------------------------------------------\n");
                printf("Error!! You entered a wrong choice.\n");
                printf("---------------------------------------------------\n");
                break;
        }
        if(!h)
            break;
    }
}