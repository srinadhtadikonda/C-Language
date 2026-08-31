/* program to append a text file */
#include<stdio.h>
#include<conio.h>
main()
{
FILE *fp;
fp=fopen("fruits.txt","a");
fputs("\nPine Apple",fp);
fputs("\nCherry",fp);
fclose(fp);
printf("\nFile Appended");
}

