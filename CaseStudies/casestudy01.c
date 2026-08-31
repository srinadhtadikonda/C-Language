/* Employee Management System using Binary File */

#include <stdio.h>
#include <stdlib.h>

struct emp
{
    int eno;
    char ename[20];
    float esal;
    char egrade;
};

/* Insert a new employee */
void insertRecord()
{
    struct emp e;
    FILE *fp;

    fp = fopen("employee.dat", "ab");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("\nEnter Employee Number: ");
    scanf("%d", &e.eno);

    printf("Enter Employee Name: ");
    scanf("%s", e.ename);

    printf("Enter Employee Salary: ");
    scanf("%f", &e.esal);

    printf("Enter Employee Grade: ");
    scanf(" %c", &e.egrade);

    fwrite(&e, sizeof(e), 1, fp);

    fclose(fp);

    printf("\nEmployee record inserted successfully.\n");
}


/* Display one employee by employee number */
void singleRecord()
{
    struct emp e;
    FILE *fp;
    int eno;
    int found = 0;

    fp = fopen("employee.dat", "rb");

    if (fp == NULL)
    {
        printf("File not found!\n");
        return;
    }

    printf("\nEnter Employee Number to search: ");
    scanf("%d", &eno);

    while (fread(&e, sizeof(e), 1, fp) == 1)
    {
        if (e.eno == eno)
        {
            printf("\n---------------------------------------------\n");
            printf("Employee Number : %d\n", e.eno);
            printf("Employee Name   : %s\n", e.ename);
            printf("Employee Salary : %.2f\n", e.esal);
            printf("Employee Grade  : %c\n", e.egrade);
            printf("---------------------------------------------\n");

            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("\nEmployee record not found.\n");

    fclose(fp);
}


/* Display all employee records */
void allRecords()
{
    struct emp e;
    FILE *fp;

    fp = fopen("employee.dat", "rb");

    if (fp == NULL)
    {
        printf("File not found!\n");
        return;
    }

    printf("\n-------------------------------------------------------------\n");
    printf("%-10s %-20s %-15s %-10s\n",
           "ENO", "ENAME", "SALARY", "GRADE");
    printf("-------------------------------------------------------------\n");

    while (fread(&e, sizeof(e), 1, fp) == 1)
    {
        printf("%-10d %-20s %-15.2f %-10c\n",
               e.eno, e.ename, e.esal, e.egrade);
    }

    printf("-------------------------------------------------------------\n");

    fclose(fp);
}


/* Update employee details */
void updateRecord()
{
    struct emp e;
    FILE *fp;
    int eno;
    int found = 0;

    fp = fopen("employee.dat", "rb+");

    if (fp == NULL)
    {
        printf("File not found!\n");
        return;
    }

    printf("\nEnter Employee Number to update: ");
    scanf("%d", &eno);

    while (fread(&e, sizeof(e), 1, fp) == 1)
    {
        if (e.eno == eno)
        {
            printf("\nExisting Record:\n");
            printf("Name   : %s\n", e.ename);
            printf("Salary : %.2f\n", e.esal);
            printf("Grade  : %c\n", e.egrade);

            printf("\nEnter New Employee Name: ");
            scanf("%s", e.ename);

            printf("Enter New Employee Salary: ");
            scanf("%f", &e.esal);

            printf("Enter New Employee Grade: ");
            scanf(" %c", &e.egrade);

            fseek(fp, -sizeof(e), SEEK_CUR);

            fwrite(&e, sizeof(e), 1, fp);

            printf("\nEmployee record updated successfully.\n");

            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("\nEmployee record not found.\n");

    fclose(fp);
}


/* Delete employee record */
void deleteRecord()
{
    struct emp e;
    FILE *fp;
    FILE *temp;
    int eno;
    int found = 0;

    fp = fopen("employee.dat", "rb");

    if (fp == NULL)
    {
        printf("File not found!\n");
        return;
    }

    temp = fopen("temp.dat", "wb");

    if (temp == NULL)
    {
        printf("Unable to create temporary file!\n");
        fclose(fp);
        return;
    }

    printf("\nEnter Employee Number to delete: ");
    scanf("%d", &eno);

    while (fread(&e, sizeof(e), 1, fp) == 1)
    {
        if (e.eno == eno)
        {
            found = 1;
        }
        else
        {
            fwrite(&e, sizeof(e), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("employee.dat");
    rename("temp.dat", "employee.dat");

    if (found == 1)
        printf("\nEmployee record deleted successfully.\n");
    else
        printf("\nEmployee record not found.\n");
}


/* Main Program */
int main()
{
    int choice;

    do
    {
        printf("\n=========================================\n");
        printf("       EMPLOYEE MANAGEMENT SYSTEM\n");
        printf("=========================================\n");

        printf("1. Insert Employee\n");
        printf("2. Display Single Employee\n");
        printf("3. Display All Employees\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");

        printf("=========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertRecord();
                break;

            case 2:
                singleRecord();
                break;

            case 3:
                allRecords();
                break;

            case 4:
                updateRecord();
                break;

            case 5:
                deleteRecord();
                break;

            case 6:
                printf("\nProgram terminated.\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}
