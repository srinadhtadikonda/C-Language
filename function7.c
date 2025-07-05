#include<stdio.h>

void displayArray(int arr[3][3]);

main()
{
    int arr[3][3], i, j;
    printf("Please enter 9 numbers for the array: \n");
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 3; ++j)
        {    
            scanf("%d", &arr[i][j]);
        }
    }
    displayArray(arr);
}

void displayArray(int arr[3][3])
{
    int i, j;
    printf("The complete array is: \n");
    for (i = 0; i < 3; ++i)
    {
        // getting cursor to new line
        printf("\n");
        for (j = 0; j < 3; ++j)
        {       
            // \t is used to provide tab space
            printf("%d\t", arr[i][j]);
        }
    }
}

