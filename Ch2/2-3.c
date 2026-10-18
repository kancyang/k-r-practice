#include <stdio.h>
#define MAXL 10

int htoi(const char *s)
{
	int q = 0;
	int f = 0;
	int i = 0;
	while (s[i] != '\0') {
		int c = s[i];
		int r;
		++i;
		if (c >= '0' && c <= '9')
			r = c - '0';
		else if (c >= 'a' && c <= 'f')
			r = c - 'a' + 10;
		else if (c >= 'A' && c <= 'F')
			r = c - 'A' + 10;
		else if ((c == 'x' || c == 'X') && f == 1)
			r = 0;
		else
			r = -1;

		if (r == -1) {
			return q;
		} else if (f == 0) {
			if (c == '0')
				f = 1;
			else
				f = 2;
		} else if (f == 1) {
			f = 2;
			continue;
		}
		q = q * 16 + r;
	}
	return q;
}

int main(void)
{
	char s[MAXL];
	if (fgets(s, sizeof(s), stdin) == NULL)
		return 1;
	printf("%d\n", htoi(s));
	return 0;
}
