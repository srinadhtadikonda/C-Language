/* program to create a text file */
#include<stdio.h>
#include<conio.h>
main()
{
FILE *fp;
fp=fopen("fruits.txt","w");
fputs("Apple",fp);
fputs("\nOrange",fp);
fputs("\nBanana",fp);
fclose(fp);
printf("\nFile Created");
}

