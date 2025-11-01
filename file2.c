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
        printf("File not found!\n");
        exit(1);
    }

    printf("EmpNo\tName\tSalary\tGrade\n");
    printf("---------------------------------\n");

    while (fread(&e, sizeof(e), 1, fp))
    {
        printf("%d\t%s\t%.2f\t%c\n", e.eno, e.ename, e.esal, e.egrade);
    }

    fclose(fp);
    return 0;
}
