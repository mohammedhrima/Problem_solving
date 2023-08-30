#include <stdlib.h>
#include <stdio.h>
/*
find all a, b so 1*a + 2*b = n
*/

void test(int n)
{
    int t1 = 0;
    int t2 = 1;
    int nextTerm = 0;
    printf("%d %d ", t1, t2);
    nextTerm = t1 + t2;
    int i = 0;

    while (i <= n)
    {
        printf("%d ", nextTerm);
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
        i++;
    }
}

int climbStairs(int n)
{
    if(n < 3 ) return n;
    int a = 1;
    int b = 2;
    int i = 3;
    while (i <= n)
    {
        int tmp = a + b;
        a = b;
        b = tmp;
        i++;
    }
    return b;
}

int main(void)
{
    int n = 3;
    // test(n);
    printf("%d\n",climbStairs(n));
}