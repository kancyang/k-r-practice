#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int setbits(unsigned int x, int p, int n, unsigned int y)
{
	unsigned int a, b;
	a = b = 0;
	int s = sizeof(unsigned int) * CHAR_BIT;
	a = ~((~a) << (s - p - 1) >> (s - n) << (p + 1 - n));
	b = (~b) >> (s - n);
	return (x & a) + ((y & b) << (p + 1 - n));
}

int main(void)
{
	char buf[32];
	unsigned int x, y;
	int s = sizeof(unsigned int) * CHAR_BIT;
	if (fgets(buf, sizeof(buf), stdin))
		x = strtol(buf, NULL, 2);
	if (fgets(buf, sizeof(buf), stdin))
		y = strtol(buf, NULL, 2);
	int p, n;
	scanf("%d %d", &p, &n);
	unsigned int z = setbits(x, p, n, y);
	printf("%0*b\n%0*b\n%0*b\n", s, x, s, y, s, z);
	return 0;
}
