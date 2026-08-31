/* program to read a text file */
#include<stdio.h>
#include<conio.h>
main()
{
FILE *fp;
char ch
fp=fopen("fruits.txt","r");
while ((ch = fgetc(fp)) != EOF)
{
 putchar(ch);
}
}
