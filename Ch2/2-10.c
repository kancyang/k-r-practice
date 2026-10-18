#include <stdio.h>
#define MAXL 100

char lower_case(char c)
{
	return (c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : c;
}

char upper_case(char c)
{
	return (c >= 'a' && c <= 'z') ? (c - 'a' + 'A') : c;
}

char change_case(char c)
{
	return (c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : upper_case(c);
}

int change_cases(char *c)
{
	int l;
	for (l = 0; c[l] != '\0'; ++l) {
		c[l] = change_case(c[l]);
	}
	return l;
}

int main(void)
{
	char a[MAXL];
	if (fgets(a, sizeof(a), stdin) == NULL)
		return 1;
	change_cases(a);
	printf("%s\n", a);
	return 0;
}
