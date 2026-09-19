/* remove comment */
/* 2026-09-19 */

#include <stdio.h>
#define	IN 1
#define OUT 0

int notg(int a)
{
	if (a == IN)
		return OUT;
	else
		return IN;
}

int main(void)
{
	int lc, c;
	int comment, lcomment, quo, dquo;
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
				continue;
			}
		}
		else if (quo == IN)
		{
			putchar(c);
			if (lc != '\\' && c == '\'')
			{
				quo = OUT;
			}
		}
		else if (dquo == IN)
		{
			putchar(c);
			if (lc != '\\' && c == '\"')
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
				dquo = IN;
			else if (c == '\'')
				quo = IN;
			if (c != '/')
				putchar(c);
		}
		lc = c;
	}

	return 0;
}
