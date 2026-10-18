void squeeze(char *s, int c)
{
	int i, j;
	for (i = j = 0; s[i] != '\0'; ++i)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
	return;
}

void strcat_(char *s, char *t)
{
	int i, j;
	i = j = 0;
	while (s[i] != '\0')
		++i;
	while ((s[i++] = t[j++]) != '\0')
		;
	return;
}

unsigned int getbits(unsigned int x, int p, int n)
{
	return (x >> (p + 1 - n)) & ~((~0) << n);
}

int bitcount(unsigned int x)
{
	int b;
	for (b = 0; x != 0; x>>=1) {
		if (x & 01)
			++b;
	}
	return b;
}

/* Amazing codes */
/*
 * for (int i = 0; i < n; ++i)
 *	printf("%6d%c", a[i], (i % 10 == 9 || i == n - 1) ? '\n' : ' ');
 * 
 * printf("You have %d item%s.\n", n, n == 1 ? "":"s");
 */
