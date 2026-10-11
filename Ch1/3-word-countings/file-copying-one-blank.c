#include <stdio.h>

int main(void)
{
    int c, p = 0;
    while((c=getchar()) != EOF)
    {
        if(!p)
            putchar(c);
        if(c == ' ')
            p = 1;
        else
            p = 0;
    }

    return 0;
}
