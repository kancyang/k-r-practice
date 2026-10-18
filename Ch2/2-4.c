#include <limits.h>
#include <stdio.h>
#define MAXL 300

void squeeze_2(char *s1, const char *s2)
{
	int d[UCHAR_MAX] = {0};
	for (int i = 0; s2[i] != '\0'; ++i) {
		d[s2[i]] = 1;
	}
	int i, j;
	for (i = j = 0; s1[i] != '\0'; ++i) {
		if (d[s1[i]] == 0)
			s1[j++] = s1[i];
	}
	s1[j] = 0;
	return;
}

int main(void)
{
	char s1[MAXL];
	char s2[MAXL];
	if (fgets(s1, sizeof(s1), stdin) == NULL)
		return -1;
	if (fgets(s2, sizeof(s2), stdin) == NULL)
		return -1;
	squeeze_2(s1, s2);
	printf("%s\n", s1);
	return 0;
}
