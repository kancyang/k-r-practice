#include <stdio.h>

int main(void)
{
    long c, b, t, n;
    while((c=getchar()) != EOF)
    {
        if(c == ' ')
            ++b;
        else if(c == '\t')
            ++t;
        else if(c == '\n')
            ++n;
    }
    printf("\nblanks:%ld\ntabs:%ld\nnewlines:%ld\n", b, t, n);

    return 0;
}
