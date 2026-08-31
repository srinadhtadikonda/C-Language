/* EMPLOYEE MANAGEMENT SYSTEM
   Using Binary File Handling
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct emp
{
    int eno;
    char ename[20];
    float esal;
    char egrade;
};


/* -------------------------------------------------
   FUNCTION TO CHECK WHETHER EMPLOYEE NUMBER EXISTS
   ------------------------------------------------- */

int employeeExists(int eno)
{
    struct emp e;
    FILE *fp;

    fp = fopen("employee.dat", "rb");

    if (fp == NULL)
        return 0;

    while (fread(&e, sizeof(e), 1, fp) == 1)
    {
        if (e.eno == eno)
        {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}


/* -------------------------------------------------
   INSERT EMPLOYEE
   ------------------------------------------------- */

void insertRecord()
{
    struct emp e;
    FILE *fp;

    printf("\nEnter Employee Number: ");
    scanf("%d", &e.eno);

    /* Check duplicate employee number */
    if (employeeExists(e.eno))
    {
        printf("\nEmployee Number already exists!\n");
        return;
    }

    printf("Enter Employee Name: ");
    scanf(" %19[^\n]", e.ename);

    /* Salary validation */
    do
    {
        printf("Enter Employee Salary: ");
        scanf("%f", &e.esal);

        if (e.esal <= 0)
            printf("Salary must be greater than 0.\n");

    } while (e.esal <= 0);


    /* Grade validation */
    do
    {
        printf("Enter Employee Grade (A/B/C/D): ");
        scanf(" %c", &e.egrade);

        if (e.egrade != 'A' &&
            e.egrade != 'B' &&
            e.egrade != 'C' &&
            e.egrade != 'D' &&
            e.egrade != 'a' &&
            e.egrade != 'b' &&
            e.egrade != 'c' &&
            e.egrade != 'd')
        {
            printf("Invalid grade!\n");
        }

    } while (e.egrade != 'A' &&
             e.egrade != 'B' &&
             e.egrade != 'C' &&
             e.egrade != 'D' &&
             e.egrade != 'a' &&
             e.egrade != 'b' &&
             e.egrade != 'c' &&
             e.egrade != 'd');


    /* Convert lowercase grade to uppercase */
    if (e.egrade >= 'a' && e.egrade <= 'd')
        e.egrade = e.egrade - 32;


    fp = fopen("employee.dat", "ab");

    if (fp == NULL)
    {
        printf("\nError opening file!\n");
        return;
    }

    fwrite(&e, sizeof(e), 1, fp);

    fclose(fp);

    printf("\nEmployee record inserted successfully!\n");
}


/* -------------------------------------------------
   DISPLAY SINGLE EMPLOYEE
   ------------------------------------------------- */

void singleRecord()
{
    struct emp e;
    FILE *fp;
    int eno;
    int found = 0;

    fp = fopen("employee.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNo employee records found.\n");
        return;
    }

    printf("\nEnter Employee Number to search: ");
    scanf("%d", &eno);

    while (fread(&e, sizeof(e), 1, fp) == 1)
    {
        if (e.eno == eno)
        {
            printf("\n----------------------------------------\n");
            printf("Employee Number : %d\n", e.eno);
            printf("Employee Name   : %s\n", e.ename);
            printf("Employee Salary : %.2f\n", e.esal);
            printf("Employee Grade  : %c\n", e.egrade);
            printf("----------------------------------------\n");

            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("\nEmployee record not found.\n");

    fclose(fp);
}


/* -------------------------------------------------
   DISPLAY ALL EMPLOYEES
   ------------------------------------------------- */

void allRecords()
{
    struct emp e;
    FILE *fp;
    int count = 0;

    fp = fopen("employee.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNo employee records found.\n");
        return;
    }

    printf("\n-------------------------------------------------------------\n");

    printf("%-10s %-20s %-15s %-10s\n",
           "ENO",
           "ENAME",
           "SALARY",
           "GRADE");

    printf("-------------------------------------------------------------\n");

    while (fread(&e, sizeof(e), 1, fp) == 1)
    {
        printf("%-10d %-20s %-15.2f %-10c\n",
               e.eno,
               e.ename,
               e.esal,
               e.egrade);

        count++;
    }

    printf("-------------------------------------------------------------\n");

    if (count == 0)
        printf("No employee records found.\n");

    fclose(fp);
}


/* -------------------------------------------------
   UPDATE EMPLOYEE
   ------------------------------------------------- */

void updateRecord()
{
    struct emp e;
    FILE *fp;
    int eno;
    int choice;
    int found = 0;

    fp = fopen("employee.dat", "rb+");

    if (fp == NULL)
    {
        printf("\nNo employee records found.\n");
        return;
    }

    printf("\nEnter Employee Number to update: ");
    scanf("%d", &eno);

    while (fread(&e, sizeof(e), 1, fp) == 1)
    {
        if (e.eno == eno)
        {
            found = 1;

            printf("\nEmployee Found!\n");

            printf("\nCurrent Details:\n");
            printf("Name   : %s\n", e.ename);
            printf("Salary : %.2f\n", e.esal);
            printf("Grade  : %c\n", e.egrade);

            printf("\n-----------------------------\n");
            printf("1. Update Name\n");
            printf("2. Update Salary\n");
            printf("3. Update Grade\n");
            printf("4. Update All\n");
            printf("5. Cancel\n");
            printf("-----------------------------\n");

            printf("Enter your choice: ");
            scanf("%d", &choice);


            /* UPDATE NAME */
            if (choice == 1)
            {
                printf("Enter New Name: ");
                scanf(" %19[^\n]", e.ename);
            }


            /* UPDATE SALARY */
            else if (choice == 2)
            {
                do
                {
                    printf("Enter New Salary: ");
                    scanf("%f", &e.esal);

                    if (e.esal <= 0)
                        printf("Salary must be greater than 0.\n");

                } while (e.esal <= 0);
            }


            /* UPDATE GRADE */
            else if (choice == 3)
            {
                do
                {
                    printf("Enter New Grade (A/B/C/D): ");
                    scanf(" %c", &e.egrade);

                    if (e.egrade != 'A' &&
                        e.egrade != 'B' &&
                        e.egrade != 'C' &&
                        e.egrade != 'D' &&
                        e.egrade != 'a' &&
                        e.egrade != 'b' &&
                        e.egrade != 'c' &&
                        e.egrade != 'd')
                    {
                        printf("Invalid grade!\n");
                    }

                } while (e.egrade != 'A' &&
                         e.egrade != 'B' &&
                         e.egrade != 'C' &&
                         e.egrade != 'D' &&
                         e.egrade != 'a' &&
                         e.egrade != 'b' &&
                         e.egrade != 'c' &&
                         e.egrade != 'd');

                if (e.egrade >= 'a' && e.egrade <= 'd')
                    e.egrade = e.egrade - 32;
            }


            /* UPDATE ALL */
            else if (choice == 4)
            {
                printf("Enter New Name: ");
                scanf(" %19[^\n]", e.ename);

                do
                {
                    printf("Enter New Salary: ");
                    scanf("%f", &e.esal);

                    if (e.esal <= 0)
                        printf("Salary must be greater than 0.\n");

                } while (e.esal <= 0);


                do
                {
                    printf("Enter New Grade (A/B/C/D): ");
                    scanf(" %c", &e.egrade);

                    if (e.egrade != 'A' &&
                        e.egrade != 'B' &&
                        e.egrade != 'C' &&
                        e.egrade != 'D' &&
                        e.egrade != 'a' &&
                        e.egrade != 'b' &&
                        e.egrade != 'c' &&
                        e.egrade != 'd')
                    {
                        printf("Invalid grade!\n");
                    }

                } while (e.egrade != 'A' &&
                         e.egrade != 'B' &&
                         e.egrade != 'C' &&
                         e.egrade != 'D' &&
                         e.egrade != 'a' &&
                         e.egrade != 'b' &&
                         e.egrade != 'c' &&
                         e.egrade != 'd');

                if (e.egrade >= 'a' && e.egrade <= 'd')
                    e.egrade = e.egrade - 32;
            }


            /* CANCEL */
            else if (choice == 5)
            {
                printf("\nUpdate cancelled.\n");
                fclose(fp);
                return;
            }

            else
            {
                printf("\nInvalid choice!\n");
                fclose(fp);
                return;
            }


            /* Move file pointer back to current record */
            if (choice >= 1 && choice <= 4)
            {
                fseek(fp, -sizeof(e), SEEK_CUR);

                fwrite(&e, sizeof(e), 1, fp);

                printf("\nEmployee record updated successfully!\n");
            }

            break;
        }
    }

    if (found == 0)
        printf("\nEmployee record not found.\n");

    fclose(fp);
}


/* -------------------------------------------------
   DELETE EMPLOYEE
   ------------------------------------------------- */

void deleteRecord()
{
    struct emp e;
    FILE *fp;
    FILE *temp;
    int eno;
    int found = 0;
    char confirm;

    fp = fopen("employee.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNo employee records found.\n");
        return;
    }

    printf("\nEnter Employee Number to delete: ");
    scanf("%d", &eno);


    /* Find record before deleting */
    while (fread(&e, sizeof(e), 1, fp) == 1)
    {
        if (e.eno == eno)
        {
            found = 1;

            printf("\nEmployee Found:\n");
            printf("ENO    : %d\n", e.eno);
            printf("Name   : %s\n", e.ename);
            printf("Salary : %.2f\n", e.esal);
            printf("Grade  : %c\n", e.egrade);

            break;
        }
    }

    fclose(fp);


    if (found == 0)
    {
        printf("\nEmployee record not found.\n");
        return;
    }


    /* Confirmation */
    printf("\nAre you sure you want to delete this record? (y/n): ");
    scanf(" %c", &confirm);

    if (confirm != 'y' && confirm != 'Y')
    {
        printf("\nDelete operation cancelled.\n");
        return;
    }


    /* Open original file */
    fp = fopen("employee.dat", "rb");

    if (fp == NULL)
    {
        printf("\nError opening file!\n");
        return;
    }


    /* Create temporary file */
    temp = fopen("temp.dat", "wb");

    if (temp == NULL)
    {
        printf("\nError creating temporary file!\n");
        fclose(fp);
        return;
    }


    /* Copy all records except selected record */
    while (fread(&e, sizeof(e), 1, fp) == 1)
    {
        if (e.eno != eno)
        {
            fwrite(&e, sizeof(e), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);


    /* Replace original file */
    if (remove("employee.dat") != 0)
    {
        printf("\nError deleting original file!\n");
        return;
    }

    if (rename("temp.dat", "employee.dat") != 0)
    {
        printf("\nError renaming temporary file!\n");
        return;
    }

    printf("\nEmployee record deleted successfully!\n");
}


/* -------------------------------------------------
   MAIN FUNCTION
   ------------------------------------------------- */

int main()
{
    int choice;

    do
    {
        printf("\n\n============================================\n");
        printf("        EMPLOYEE MANAGEMENT SYSTEM\n");
        printf("============================================\n");

        printf("1. Insert Employee\n");
        printf("2. Display Single Employee\n");
        printf("3. Display All Employees\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");

        printf("============================================\n");

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
                printf("\nThank you! Program terminated.\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}
