/* Program to copy one file to another file */

#include<stdio.h>
#include<conio.h>

main()
{
    FILE *fp1, *fp2;
    int inchar;

    fp1 = fopen("fruits.txt", "r");
    fp2 = fopen("copy.txt", "w");

    inchar = getc(fp1);

    while (inchar != EOF)
    {
        putc(inchar, fp2);
        inchar = getc(fp1);
    }

    fclose(fp1);
    fclose(fp2);
}
