/* Structure using functions */

#include<stdio.h>
#include<conio.h>

struct books 
{
    int bno;
    char bname[20];
    float bprice;
};

void bdet(struct books b);          /* Naming a function */

void bdet(struct books b)
{
    printf("\nNumber=%d",b.bno);        /* Function body */
    printf("\nName=%s",b.bname);
    printf("\nPrice=%0.2f",b.bprice);
    
}

void main()
{
   struct books b={1,"Unix",355.75};
   bdet(b);             /* Calling a function */
}


