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

    fp = fopen("employee.dat", "rb");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("\n-------------------------------------------------------\n");
    printf("%-15s %-20s %-12s %-10s\n",
           "Employee No", "Employee Name", "Salary", "Grade");
    printf("-------------------------------------------------------\n");

    while (fread(&e, sizeof(e), 1, fp) == 1)
    {
        printf("%-15d %-20s %-12.2f %-10c\n",
               e.eno, e.ename, e.esal, e.egrade);
    }

    printf("-------------------------------------------------------\n");

    fclose(fp);

    return 0;
}
