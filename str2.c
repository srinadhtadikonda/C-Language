/* Length of String without using function */
#include<stdio.h>
#include<conio.h>
#include<string.h>
main()
{
    char str[100];
    int c=0,i;
    printf("Enter A string..:");
    scanf("%[^\n]",&str);
    printf("\nString=%s",str);
    for(i=0;str[i]!='\0';++i)
    {
    c=c+1;
    }
printf("\nLength of String=%d",c);
}
