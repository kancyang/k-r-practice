#include <stdio.h>

int main(void)
{
    int c, i, j, nw, noc;
    int nd[10];

    nw = noc =0;
    for (i = 0; i < 10; ++i)
        nd[i] = 0;

    while((c = getchar()) != EOF)
    {
        if (c >= '0' && c<= '9')
            ++nd[c - '0'];
        else if (c == ' ' || c == '\t' || c == '\n')
            ++nw;
        else
            ++noc;
    }

    for (i = 0; i < 10; ++i)
    {
        printf("Num %d       ", i);
        for (j = 0; j < nd[i]; ++j)
            printf("[]");
        printf(" %d\n", nd[i]);
    }

    printf("White spaces");
    for (j = 0; j < nw; ++j)
            printf("[]");
    printf(" %d\n", nw);

    printf("Other chars ");
    for (j = 0; j < noc; ++j)
        printf("[]");
    printf(" %d\n", noc);

    return 0;
}
