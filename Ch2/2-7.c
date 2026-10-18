#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int invert(unsigned int x, int p, int n)
{
	int s = sizeof(unsigned int) * CHAR_BIT;
	unsigned int a = 0;
	a = (~a) << (s - p - 1) >> (s - n) << (p + 1 - n);
	return (x & (~a)) + ((x & a) ^ (a));
}

int main(void)
{
	char buf[32];
	unsigned int x;
	int s = sizeof(unsigned int) * CHAR_BIT;
	if (fgets(buf, sizeof(buf), stdin))
		x = strtol(buf, NULL, 2);
	int p, n;
	scanf("%d %d", &p, &n);
	unsigned int z = invert(x, p, n);
	printf("%0*b\n%0*b\n", s, x, s, z);
	return 0;
}
