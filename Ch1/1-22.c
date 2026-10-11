/* fold long line */
/* 2026-07-26 */
/* line buffer version */

#include <stdio.h>
#include <stdlib.h>

#define MINLEN 20
#define MAXLEN 180
#define DEFLEN 80
#define MINTAB 2
#define MAXTAB 24
#define DEFTAB 8
#define RETLEN 12   /* If a word is longer than RETLEN, use "-" to fold it. */

int main(int argc, char *argv[])
{
    /* Initialize. */
    int nl = DEFLEN;
    int tl = DEFTAB;
    int cl = 0;     /* COUNTING column */
    int wp = -1;     /* whitespace place */
    int ws = 0;     /* whitespace sign */
    int c = 0;      /* getchar character */
    int i = 0;      /* index of line */

    if (argc > 1)
    {
        nl = atoi(argv[1]);
        if (nl < MINLEN || nl > MAXLEN)
            printf("Unexpected line length! Set to be %d.\n", nl = DEFLEN);
    }
    if (argc > 2)
    {
        tl = atoi(argv[2]);
        if (tl < MINTAB || tl >MAXTAB || tl > nl)
            printf("Unexpected tabstop! Set to be %d.\n", tl = DEFTAB);
    }

    char line[nl + 1];

    /* Read and output. */
    while ((c = getchar()) != EOF)
    {
        line[i] = c;
        ++i;
        /* Identify. */
        if (c == '\n')
        {
            line[i] = 0;
            printf("%s", line);
            ws = cl = i = 0;
            wp = -1;
        }
        else if (c == '\t')
        {
            cl += tl - (cl % tl);
            if (!ws)
                wp = i - 1;
            ws = 1;
        }
        else if (c == ' ')
        {
            ++cl;
            if (!ws)
                wp = i - 1;
        }
        else
        {
            ws = 0;
            ++cl;
        }

        if (cl >= nl)
        {
            line[i] = 0;
            if (i - wp < RETLEN && wp >= 0)
            {
                line[wp] = '\n';
                printf("%s", line);
                cl = 0;
                /* Recount cl. */
                for (i = wp; line[i+1] != 0; ++i)
                {
                    if (line[i+1] == '\t')
                        cl += tl - (cl % tl);
                    else
                        ++cl;
                }
                i = 0;
            }
            else
            {
                c = line[i - 1];
                line[i - 1] = '-';
                printf("%s\n", line);
                cl = i = 1;
                line[0] = c;
            }
            wp = -1;
        }
    }
    line[i] = 0;
    printf("%s\n", line);

    return 0;
}
