#include <stdio.h>
#define MAXLINE 1000

int readaline(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
    int len, max;
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE];

    max = 0;
    while ((len = readaline(line, MAXLINE)) > 0)
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    if (max > 0)
        printf("\n%s\n", longest);
    return 0;
}

/* read a newline and return its length */
int readaline(char s[], int lim)
{
    int c, i;

    for (i = 0; (i < lim - 1) && ((c = getchar()) != EOF) && (c != '\n'); ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy line from from[] to to[] */
void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
