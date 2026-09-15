#include<stdio.h>
#include<conio.h>
main()
{
    int n,r,s=0,i=1;
    printf("Enter a number..:");
    scanf("%d",&n);
    for(i=n;i>0;i=i/10)
    {
        r=i%10;
        s=s+(r*r*r);
    }
if(n==s)
{
    printf("armstrong");
}
else
{
    printf("Not");
}
}
