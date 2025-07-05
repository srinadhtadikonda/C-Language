#include<stdio.h>
#include<conio.h>

int sumarray(int a[]);

int sumarray(int a[])
{
int i,s=0;
for(i=0;i<5;i++)
{
s=s+a[i];
}
return s;
}
main()
{
    int a[] = {10, 20, 30, 40, 50};
   printf("%d",sumarray(a));
}
