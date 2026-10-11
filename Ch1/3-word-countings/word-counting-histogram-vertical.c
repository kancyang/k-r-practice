#include <stdio.h>

#define MAX_LEN 5

int main(void)
{
    int c, i, j, index, max;
    int word[MAX_LEN];

    index = max = 0;
    for (i = 0; i < MAX_LEN; ++i)
        word[i] = 0;

    while ((c = getchar()) != EOF)
    {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
            ++word[index];
        else
            ++index;
        if (index >= MAX_LEN)
            break;
    }

    for (i = 0; i < MAX_LEN; ++i)
        if (word[i] > max)
            max = word[i];

    for (j = max; j > 0; --j)
    {
        for (i = 0; i < MAX_LEN; ++i)
            if (word[i] >= j)
                printf(" * ");
            else
                printf("   ");
        putchar('\n');
    }

    return 0;
}
