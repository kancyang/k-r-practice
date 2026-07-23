#include <stdio.h>

#define MAX 300
#define MIN 0
#define STEP 20

float fahrtcels(float);

int main(void)
{
    float i;
    for (i = MIN; i <= MAX; i = i + STEP)
        printf("%6.1f\t%6.1f\n", i, fahrtcels(i));
    return 0;
}

float fahrtcels(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32);
}
