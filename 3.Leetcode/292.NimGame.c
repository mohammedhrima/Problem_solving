#include <stdbool.h>
#include <stdio.h>
/* n = 3a + 1b */

bool canWinNim(int n)
{
    int pos = 1;
    while (n > 0)
    {
        n = n - 3;
        pos = (pos + 1) % 2;
        if (n <= 0)
            break;
        n = n - 1;
        pos = (pos + 1) % 2;
    }
    return (pos == 0);
}

int main(void)
{
    printf("%d\n", canWinNim(1));
}