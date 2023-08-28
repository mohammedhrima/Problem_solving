#include <stdio.h>
#include <limits.h>

int reverse(int x)
{
    if(x == INT_MIN) return 0;
    long sign = x >= 0 ? 1 : -1;
    x *= sign;
    long y = 0;
    while (x)
    {
        y = y * 10 + x % 10;
        if(y > INT_MAX) return 0;
        x /= 10;
    }
    return ((int)(y * sign));
}


int main(void)
{
    int x = 120;
    printf("%d\n", reverse(x));
}