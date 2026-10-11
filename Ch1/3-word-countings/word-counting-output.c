#include <stdio.h>

int main(void)
{
    int c, p = 0; /* p = 0 stands for in a word */
    while ((c = getchar()) != EOF)
    {
        if (c != ' ' && c != '\t')
        {
            p = 0;
            putchar(c);
        }
        else if (! p)
        {
            p = 1;
            printf("\n");
        }
    }
    return 0;
}
