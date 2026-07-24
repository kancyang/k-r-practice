/* detab */
/* 2026-07-24 */

#include <stdio.h>
#include <stdlib.h> /* import atoi() */
#define MAXTABSTOP 24

int main(int argc, char *argv[])
{
    int count, n, c;
    count = 0;

    if (argc > 1)
        n = atoi(argv[1]); /* turn argv[0] into int */

    if (argc < 2 || n < 1 || n > MAXTABSTOP)
    {
        printf("Unexpected argument!\nTabstop is set to be 8.\n");
        n = 8;
    }

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
            for (; count < n; ++count)
                putchar(' ');
        else
        {
            putchar(c);
            ++count;
        }
        if (count >= n || c == '\n')
            count = 0;
    }

    return 0;
}
