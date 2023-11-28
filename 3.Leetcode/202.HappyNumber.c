#include <stdbool.h>

int pow2(int n)
{
    return n * n;
}

int getSum(int n)
{
    int m = 0;
    while (n)
    {
        m += pow2(n % 10);
        n /= 10;
    }
    return m;
}

bool isHappy(int n)
{
    int st = n;
    int nd = getSum(n);
    while (st != 1 && st != nd)
    {
        st = getSum(st);
        nd = getSum(getSum(nd));
    }
    return st == 1;
}
