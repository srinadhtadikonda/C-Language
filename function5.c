#passing function to an array */
#include <stdio.h>
#include<conio.h>
void showarray(int a[5], int n) 
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}

main()
{
    int a[] = {10, 20, 30, 40, 50};
    showarray(a, 5);
}
