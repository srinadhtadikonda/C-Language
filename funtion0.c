#include<stdio.h>
#include<conio.h>
void iname();
void iname()
{
    printf("Brilliant");
}
main()
{
    clrscr();
    iname();
}



#include<stdio.h>
#include<conio.h>

char *iname();

char *iname()
{
    return "Brilliant";
}

void main()
{
    clrscr();
    printf("%s", iname());
    getch();
}
