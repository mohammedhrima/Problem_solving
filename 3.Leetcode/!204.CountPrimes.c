#include <stdio.h>
#include <stdbool.h>

int isprime(int n)
{
    if (n < 2)
        return 0;
    int i = 2;
    while (i < n / 4 + 1)
    {
        if (!(n % (n / 2 + i)))
            return 0;
        if (!(n % i))
            return 0;
        i++;
    }
    return 1;
}

int countPrimes(int n)
{
    if (n <= 2)
        return 0;
    int res = 1;
    for (int i = 3; i < n; i++)
        res += isprime(i);
    return res;
}

int main(void)
{
    printf("%d\n", countPrimes(79));
}