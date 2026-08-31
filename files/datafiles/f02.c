#include <stdio.h>
#include <stdlib.h>

struct emp
{
    int eno;
    char ename[20];
    float esal;
    char egrade;
};

int main()
{
    struct emp e;
    FILE *fp;
    char choice;

    fp = fopen("employee.dat", "ab");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    do
    {
        printf("Enter Employee Number: ");
        scanf("%d", &e.eno);

        printf("Enter Employee Name: ");
        scanf("%s", e.ename);

        printf("Enter Employee Salary: ");
        scanf("%f", &e.esal);

        printf("Enter Employee Grade: ");
        scanf(" %c", &e.egrade);

        fwrite(&e, sizeof(e), 1, fp);

        printf("Record appended successfully!\n");

        printf("Do you want to add another record (y/n)? ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    fclose(fp);

    printf("Records appended to employee.dat successfully.\n");

    return 0;
}
