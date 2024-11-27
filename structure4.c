/* Accepting values using a structure */

#include<stdio.h>
#include<conio.h>
struct emp 
{
    int eno;
    char ename[20];
    float esal;
    char egrade[2];
};
void main()
{
    struct emp e;
    
    printf("Enter Eno..:");
    scanf("%d",&e.eno);
    
    printf("Enter Ename..:");
    scanf("%s",&e.ename);
    
    printf("Enter Esal..:");
    scanf("%f",&e.esal);
    
    printf("Enter Egrade..:");
    scanf("%s",&e.egrade);
    
clrscr();
printf("\nNumber=%d",e.eno);
printf("\nName=%s",e.ename);
printf("\nSalary=%0.2f",e.esal);
printf("\nGrade=%s",e.egrade);
}

