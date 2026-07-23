#include <stdio.h>

int main(void)
{
    int c, i, nw, no;
    int nd[10];

    nw = no = 0;
    for (i =0; i<10; ++i)
        nd[i] = 0;

    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')
            ++nd[c - '0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nw;
        else
            ++no;
    }

    printf("digits:\n");
    for (i = 0; i<10; ++i)
        printf("%d %ds\n", nd[i], i);
    printf("%d white spaces\n%d other chars\n", nw, no);
    
    return 0;
}
