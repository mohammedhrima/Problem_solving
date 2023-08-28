#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool isPalindrome(int x)
{
    int y = x;
    long long int z = 0;

    while (y > 0)
    {
        z = 10 * z + y % 10;
        y = y / 10;
    }
    if (z == x)
        return true;
    return false;
}

int main(void)
{
    printf("-> %d\n", isPalindrome(121));
}
