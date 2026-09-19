/* remove comment */
/* 2026-09-19 */

#include <stdio.h>
#define	IN 1
#define OUT 0

int main(void)
{
	int lc, c;
	int comment = OUT, lcomment = OUT, quo = OUT, dquo = OUT;
	int bs = OUT;
	lc = ' ';
	while ((c = getchar()) != EOF)
	{
		if (comment == IN)
		{
			if (lc == '*' && c == '/')
			{
				lc = ' ';
				comment = OUT;
				continue;
			}
		}
		else if (lcomment == IN)
		{
			if (c == '\n')
			{
				lc = ' ';
				lcomment = OUT;
				putchar('\n');
				continue;
			}
		}
		else if (quo == IN)
		{
			putchar(c);
			if (bs == IN)
				bs = OUT;
			else if (c == '\\')
				bs = IN;
			else if (c == '\'')
				quo = OUT;
		}
		else if (dquo == IN)
		{
			putchar(c);
			if (bs == IN)
				bs = OUT;
			else if (c == '\\')
				bs = IN;
			else if (c == '\'')
				dquo = OUT;
		}
		else
		{
			if (lc == '/')
			{
				if (c == '*')
				{
					comment = IN;
					lc = ' ';
					continue;
				}
				else if (c == '/')
				{
					lcomment = IN;
					lc = ' ';
					continue;
				}
				else
					putchar('/');
			}
			if (c == '\"')
			{
				dquo = IN;
				bs = OUT;
			}
			else if (c == '\'')
			{
				quo = IN;
				bs =OUT;
			}
			if (c != '/')
				putchar(c);
		}
		lc = c;
	}
	if (lc == '/')
		putchar('/');

	return 0;
}
