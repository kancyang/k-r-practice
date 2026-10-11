#include <stdio.h>

int main(void)
{
    int nl, nw, nc, c, state;
    nl = nw = nc =0;
    state = 1; /* state=1 : last char is blank or tab or newline */
    
    while ((c=getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' '||c == '\n'||c == '\t')
            state = 1;
        else if (state)
        {
            ++nw;
            state = 0;
        }
    }
    printf("\n%d newlines; %d words; %d chars\n", nl, nw, nc);

    return 0;
}
