# Important

1. Remind that (~0) >> 1 may add 0 or 1 at the left end, use UNSIGNED to surely add 0! Like this:
```
unsigned int a = 0;
a = (~a) >> 1;
```
INSTEAD of:
```
unsigned int a = (~0) >> 1;
```

2. Maybe I should organize all the exercise about bit operate into one file, since they have repetitive code, which should be written as a function. For instance, return the `n`bits-mask from position `p` and count the length of a number.
```
unsigned int bit_mask(int l, int p, int n)
{
    unsigned int a = 0;
    a = (~a) << (l - p - 1) >> (l - n) << (p + 1 - n);
    return a;
}

int bit_len(unsigned x)
{
    int l = 0;
    while (x > 0) {
        x >>= 1;
        ++l;
    }
    return l;
}
```

