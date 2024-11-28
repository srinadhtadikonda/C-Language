#include<stdio.h>
#include<cono.h>
struct emp
{
    int eno;
    char ename[20];
    float esal;
    char egrade[3];
struct dept
{
    int deptno;
    char deptname[20];
}e;
}d;
void main()
{
    
    printf("Enter Eno..:");
    scanf("%d",&e.eno);
    
    printf("Enter Ename..:");
    scanf("%s",&e.ename);
    
    printf("Enter Esal..:");
    scanf("%f",&e.esal);
    
    printf("Enter Egrade..:");
    scanf("%d",&e.eno);
    
    printf("Enter Deptno..:");
    scanf("%d",&e.d.deptno);
    
    printf("Enter Deptname..:");
    scanf("%s",&e.d.deptname);
    
    clrscr();
    printf("\n-----------------------------------------------------------------");
    printf("\n\tEMPLOYEE DATA");
    printf("\n-----------------------------------------------------------------");
    printf("\nNumber=%d",e.eno);
    printf("\nName=%s",e.ename);
    printf("\nSalary=%0.2f",e.esal);
    printf("\nGrade=%s",e.egrade);
    printf("\nGrade=%s",e.d.deptno);
    printf("\nGrade=%s",e.d.deptname);
    printf("\n-----------------------------------------------------------------");
}

