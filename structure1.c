#include<stdio.h>
#include<conio.h>
typedef struct
{
    int eno;
    char ename[20];
    float esal;
    char egrade;
}emp;
void main()
{
    emp e={111,"amar",3555.85,'b'};
    printf("\nEno=%d",e.eno);
    printf("\nEname=%s",e.ename);
    printf("\nEsal=%0.2f",e.esal);
    printf("\nEgrade=%c",e.egrade);
    
}