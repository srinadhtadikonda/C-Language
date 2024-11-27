/* Structure with pointer */
#include<stdio.h>
#include<conio.h>

struct books 
{
    int bno;
    char bname[20];
    float bprice;
};

void main()
{
       struct books b={1,"Unix",355.75},*ptr=NULL;
       ptr=&b;
    printf("\nNumber=%d",ptr->bno);       
    printf("\nName=%s",ptr->bname);
    printf("\nPrice=%0.2f",ptr->bprice);

}

