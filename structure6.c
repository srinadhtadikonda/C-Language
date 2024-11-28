/* structure with array */

#include<stdio.h>
#include<conio.h>
struct student 
{
    int sno;
    char sname[20];
    int sclass;
    char ssec[3];
};
void main()
{
    struct student s[100];
    int n,i;

    clrscr();

    printf("Enter Number of Students..:");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
    printf("Enter Sno..:");
    scanf("%d",&s[i].sno);

    printf("Enter Sname..:");
    scanf("%s",&s[i].sname);


    printf("Enter Sclass..:");
    scanf("%d",&s[i].sclass);


    printf("Enter Ssec..:");
    scanf("%s",&s[i].ssec);
    }

    clrscr();

    printf("\n------------------------------------------------------------------");
    printf("\nSTUDENT DETAILS");
    printf("\n------------------------------------------------------------------");
    printf("\nSno\tSname\tSclass\tSsec");
    printf("\n------------------------------------------------------------------");

    for(i=0;i<n;i++)
    {
        printf("\n%d\t%s\t%d\t%s",s[i].sno,s[i].sname,s[i].sclass,s[i].ssec);
    }
    printf("\n-------------------------------------------------------------------");
}

    
    
