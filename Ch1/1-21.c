/* entab, removed trailing whitespaces */
/* 2026-07-24 */

#include <stdio.h>
#include <stdlib.h>

#define MAXTABSTOP 24

int main(int argc, char *argv[])
{
    int ns, nt, count, n, c;
    /* num of space, tab; a white count; tabstop; getchar */

    if (argc > 1)
        n = atoi(argv[1]);
    if (argc < 2 || n < 1 || n > MAXTABSTOP)
    {
        printf("Unexpected argument! Tabstop is set to be 8.\n");
        n = 8;
    }
    
    ns = nt = count = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            ++count;
            ++ns;
        }
        else if (c == '\t')
        {
            count = ns = 0;
            ++nt;
        }
        else if (c == '\n')
        {
            count = ns = nt = 0; /* Remove trailing whitespaces. */
            putchar('\n');
        }
        else
        {
            for (; nt > 0; --nt)
                putchar('\t');
            for (; ns > 0; --ns)
                putchar(' ');
            putchar(c);
            ++count;
        }

        if (count >= n)
        {
            count = 0;
            if (ns > 1) /* If a ' ' or a '\t' both ok, choose ' '. */
            {
                ns = 0;
                ++nt;
            }
        }
    }

    return 0;
}
