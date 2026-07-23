#include <stdio.h>

int main(void)
{
    int c,nl;

    while((c=getchar()) != EOF)
        if(c == '\n')
            ++nl;
    printf("%d\n", nl);

    return 0;
}
