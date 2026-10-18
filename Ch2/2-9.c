/*
 * In a two's complete number system,
 * x - 1 is a number that the rightmost 1-bit
 * turned to be 0, while all 0-bits behind it to be 1.
 * Then x & (x - 1) is a number that is simply x,
 * except the rightmost 1-bit turned into 0.
 * So x &= (x - 1) will deletes the rightmost 1-bit.
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int bitcount_2(unsigned int x)
{
	int b;
	for (b = 0; x != 0; ++b)
		x &= (x - 1);
	return b;
}

int main(void)
{
	char buf[sizeof(unsigned int) * CHAR_BIT];
	unsigned int x = 0;
	if (fgets(buf, sizeof(buf), stdin))
		x = strtol(buf, NULL, 2);
	printf("%b\n%d\n", x, bitcount_2(x));
	return 0;
}
