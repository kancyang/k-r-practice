#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int bitlen(unsigned int x)
{
	int l = 0;
	while (x > 0) {
		x >>= 1;
		++l;
	}
	return l;
}

int rightrot(unsigned int x, int n)
{
	unsigned int a = 0;
	unsigned int z = x;
	a = ~((~a) << n);
	return (x >> n) + ((x & a) << (bitlen(x) - n));
}


int main(void)
{
	char buf[32];
	unsigned int x;
	if (fgets(buf, sizeof(buf), stdin))
		x = strtol(buf, NULL, 2);
	int l = bitlen(x);
	int n;
	scanf("%d",&n);
	unsigned int z = rightrot(x, n);
	printf("%0*b\n%0*b\n", l, x, l, z);
	return 0;
}
