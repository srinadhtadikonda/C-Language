/* Program to rename a file */

#include<stdio.h>
#include<conio.h>

main()
{
    int result;

    result = rename("fruits.txt", "vegetables.txt");

    if (result == 0)
        printf("File renamed successfully.");
    else
        printf("Unable to rename the file.");
}
