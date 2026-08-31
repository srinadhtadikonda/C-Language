/* Program to read a text file */
#include<stdio.h>
#include<conio.h>

main()
{
    FILE *fp;
    int inchar;
    fp = fopen("fruits.txt", "r");
    inchar = getc(fp);
    while (inchar != EOF)
    {
        putchar(inchar);
        inchar = getc(fp);
    }
   fclose(fp);
}
