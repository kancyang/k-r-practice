#include <limits.h>
#include <stdio.h>
#define MAXL 300

int any(const char *s1, const char *s2)
{
	int d[UCHAR_MAX + 1] = {0};
	for (int i = 0; s2[i] != '\0'; ++i)
		d[s2[i]] = 1;
	for (int i = 0; s1[i] != '\0'; ++i)
		if (d[s1[i]] == 1)
			return i;
	return -1;
}

int main(void)
{
	char s1[MAXL];
	char s2[MAXL];
	/* 299 == MAXL - 1 */
	scanf("%299s %299s", s1, s2);
	printf("%d\n", any(s1, s2));
	return 0;
}
