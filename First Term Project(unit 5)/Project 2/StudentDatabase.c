#include "StudentDatabase.h"

extern Student Database[50];
int count = 0;

void Add_Student_Manually()
{
    printf("\nAdd student info:\n");
    printf("Enter the roll number: ");
    erase
    scanf("%d", &(Database[count].Roll));
    int i;
    for(i=0; i<count; i++)
    {
        if(Database[i].Roll == Database[count].Roll)
        {
            printf("Error!! The student roll number already exists!\n");
            return;
        }
    }

    printf("Enter the first name: ");erase
    scanf("%s", (Database[count].FirstName));

    printf("Enter the last name: ");erase
    scanf("%s", (Database[count].LastName));

    printf("Enter the GPA: ");erase
    scanf("%f", &(Database[count].GPA));

    for(i=0; i<sizeof(Database[count].CId);i++)
    {
        Database[count].CId[i] = 0;
    }

    printf("Enter the number of subjects: ");erase
    int subjects;
    scanf("%d", &subjects);

    printf("\nEnter the course ID of each course:\n");erase
    for(i=0; i<subjects; i++)
    {
        printf("Course %d ID: ", i+1);erase
        scanf("%d", &(Database[count].CId[i]));

        int j;
        for(j=0; j<(sizeof(Database->CId)/4); j++)
        {
            if(i==j)
                continue;
            if(Database[count].CId[i] == Database[count].CId[j])
            {
                printf("Already used course ID.\n");
                i--;
                break;
            }
        }
    }
    count++;
}

void Total_Students()
{
    printf("-------------INFO-------------\n");
    printf("-The total number of students: %d.\n", count);
    printf("-You can add up to %d students.\n", sizeof(Database)/sizeof(Student));
    printf("-You can add %d more students.", (sizeof(Database)/sizeof(Student)) - count);
}

void Add_Student_File()
{
    FILE *ptr;

    ptr = fopen("student.txt", "r");

    if(ptr == NULL) {
        printf("[ERROR] Not able to open the file.\n");
        fclose(ptr);
        return;
    }
    while(!feof(ptr)){
        int v=0;
        fscanf(ptr,"%d" , &(Database[count].Roll));
        int i;
        for(i=0; i<count; i++)
        {
            if(Database[i].Roll == Database[count].Roll)
            {
                printf("Error!! The student roll number already exists! (roll number: %d)\n", Database[count].Roll);
                v=1;
            }
        }
        fscanf(ptr,"%s" , (Database[count].FirstName));
        fscanf(ptr,"%s" , (Database[count].LastName));
        fscanf(ptr,"%f" , &(Database[count].GPA));

        for(i=0; i<sizeof(Database[count].CId)/4;i++)
        {
            Database[count].CId[i] = 0;
        }
        for(i=0; i<5; i++)
        {

            fscanf(ptr,"%d" , &(Database[count].CId[i]));


        }
        if(v == 0)
            count++;
    }
    fclose(ptr);
}

void Show_Student()
{
    int i;
    for(i=0; i<count; i++)
    {
        printf("\nStudent first name: %s\n", Database[i].FirstName);
        printf("Student last name: %s\n", Database[i].LastName);
        printf("Student roll number: %d\n", Database[i].Roll);
        printf("Student GPA: %.2f\n", Database[i].GPA);
        int j;
        for(j=0; Database[i].CId[j] != 0 && j<sizeof(Database[count].CId)/4; j++)
        {
            printf("Course No. %d ID: %d\n",j+1, Database[i].CId[j]);
        }

    }
    Total_Students();
}

void Find_FirstName()
{
    char first[30];
    printf("Enter the first name of the student: ");erase
    scanf("%s", first);
    int Nchar=0;
    int i,j;
    for(i=0; i<sizeof(first); i++)
    {
        if(first[i]==0)
            break;
        else Nchar++;
    }

    int arr[count], Narr=0;

    for(j=0; j<count; j++)
    {
        int num=0;
        for(i=0; i<Nchar; i++)
        {
            if(first[i] == Database[j].FirstName[i] || first[i]+32 == Database[j].FirstName[i] || first[i]-32 == Database[j].FirstName[i])
            {
                num++;
            }

        }
        if(num == Nchar)
        {
            arr[Narr] = j;
            Narr++;
        }
    }

    if(Narr != 0)
    {
        for(i=0; i<Narr; i++)
        {
            printf("The student details are:\n");
            printf("\nStudent first name: %s\n", Database[arr[i]].FirstName);
            printf("Student last name: %s\n", Database[arr[i]].LastName);
            printf("Student roll number: %d\n", Database[arr[i]].Roll);
            printf("Student GPA: %.2f\n", Database[arr[i]].GPA);
            for(j=0; Database[arr[i]].CId[j] != 0 && j<sizeof(Database[count].CId)/4; j++)
            {
                printf("Course No. %d ID: %d\n",j+1, Database[arr[i]].CId[j]);
            }
        }
    }
    else printf("Error!! First name %s not found. \n", first);
}

void Find_By_Number()
{
    int search;

    printf("Enter the roll number of the student: ");erase
    scanf("%d", &search);


    int i;
    for(i=0; i<count; i++)
    {
        if(search == Database[i].Roll)
        {
            printf("The student details are:\n");
            printf("\nStudent first name: %s\n", Database[i].FirstName);
            printf("Student last name: %s\n", Database[i].LastName);
            printf("Student roll number: %d\n", Database[i].Roll);
            printf("Student GPA: %.2f\n", Database[i].GPA);
            int j;
            for(j=0; Database[i].CId[j] != 0 && j<sizeof(Database[count].CId)/4; j++)
            {
                printf("Course No. %d ID: %d\n",j+1, Database[i].CId[j]);
            }
            break;
        }
    }
    if(i == count)
    {
        printf("The roll number doesn't exist.\n");
    }
}

void Find_DetByCourses()
{
    int id;
    printf("Enter the course ID: ");erase
    scanf("%d", &id);

    int i ,j;
    int arr[count], Narr=0;
    for(i=0; i<count; i++)
    {
        for(j=0; j<(sizeof(Database->CId)/4); j++)
        {
            if(id == Database[i].CId[j])
            {
                arr[Narr] = i;
                Narr++;
            }
        }
    }

    for(i=0; i<Narr; i++)
    {
        printf("\nThe student details are:\n");
        printf("\nStudent first name: %s\n", Database[arr[i]].FirstName);
        printf("Student last name: %s\n", Database[arr[i]].LastName);
        printf("Student roll number: %d\n", Database[arr[i]].Roll);
        printf("Student GPA: %.2f\n", Database[arr[i]].GPA);
    }
    printf("\nInfo:-Total number of students enrolled: %d", Narr);
}

void Delete_Student()
{
    int id;
    printf("Enter the roll number which you want to delete: ");erase
    scanf("%d", &id);

    int i;
    for(i=0; i<count; i++)
    {
        if(id == Database[i].Roll)
        {
            break;
        }
    }

    if(i == count)
    {
        printf("Error!! This roll number doesn't exist.\n");
        return;
    }


    for(int j=i+1; j<(count); j++)
    {
        Database[i] = Database[j];
        i++;
    }

    Database[i].Roll = -1;
    printf("Info:- The roll number is removed successfully.\n");
    count--;
}



void Update_Student()
{
    int id;
    printf("Enter the roll number to update the entry: ");erase
    scanf("%d", &id);

    int i;
    for(i=0; i<count; i++)
    {
        if(id == Database[i].Roll)
            break;
    }

    if(i == count)
    {
        printf("Error!! This roll number doesn't exist.\n");
        return;
    }

    int num;
    printf("1. first name\n");
    printf("2. last name\n");
    printf("3. roll number\n");
    printf("4. GPA\n");
    printf("5. courses\nEnter the category No.: ");erase
    scanf("%d", &num);

    int number;

    switch (num)
    {
        case 1:
            printf("Enter the new first name: ");erase
            scanf("%s", Database[i].FirstName);
            printf("UPDATED\n");
            break;

        case 2:
            printf("Enter the new last name: ");erase
            scanf("%s", Database[i].LastName);
            printf("UPDATED\n");
            break;

        case 3:
            printf("Enter the new roll number: ");erase
            scanf("%d", &(Database[i].Roll));
            printf("UPDATED\n");
            break;

        case 4:
            printf("Enter the new GPA: ");erase
            scanf("%f", &(Database[i].GPA));
            printf("UPDATED\n");
            break;

        case 5:
            printf("Enter the new number of courses: ");erase
            scanf("%d", &number);
            int k,j;
            for(k=0; k<number; k++)
            {
                printf("Course %d ID: ", k+1);erase
                scanf("%d", &(Database[i].CId[k]));
                for(j=0; j<(sizeof(Database->CId)/4); j++)
                {
                    if(k==j)
                        continue;
                    if(Database[i].CId[k] == Database[i].CId[j])
                    {
                        printf("Already used course ID.\n");
                        k--;
                        break;
                    }
                }
            }
            printf("UPDATED\n");
            break;
    }
}
