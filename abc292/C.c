#include <stdio.h>

void print_spliters(int num)
{
    int n = num / 2;
    while (n > 0)
    {
        if (num % n == 0)
            printf("%d\n", n);
        n--;
    }
}

int main(void)
{
    int N; // 2 <= N
    scanf("%d", &N);
    print_spliters(N);
}