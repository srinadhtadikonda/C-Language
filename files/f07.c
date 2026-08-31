/* Program to delete a file */

#include<stdio.h>
#include<conio.h>

main()
{
    int result;

    result = remove("fruits.txt");

    if (result == 0)
        printf("File deleted successfully.");
    else
        printf("Unable to delete the file.");
}
