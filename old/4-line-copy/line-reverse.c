#include <stdio.h>

#define MAXLEN 1000
#define MAXLENLEN 4
#define MAXLINE 100

int read_line(char s[], int lim);

int main(void)
{
    int i;
    int len[MAXLINE] = {0};
    char input_line[MAXLINE][MAXLEN] = {0};

    for (i = 0; (len[i] = read_line(input_line[i], MAXLEN)) > 0; ++i)
        ;
    putchar('\n');
    for (--i; i >= 0; --i)
        printf("%*d\t%s\n", MAXLENLEN, len[i], input_line[i]);
    
    return 0;
}

int read_line(char s[], int lim)
{
    int l;

    for (l = 0; l < lim - 1 && (s[l] = getchar()) != EOF && s[l] != '\n'; ++l)
        ;
    s[l] = 0;
    for (--l; (s[l] == ' ' || s[l] == '\t') && l >= 0; --l)
        s[l] = 0;
    return l+1;
}

