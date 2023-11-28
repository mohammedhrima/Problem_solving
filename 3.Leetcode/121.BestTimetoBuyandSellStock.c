#include <stdio.h>

int maxProfit(int *prices, int pricesSize)
{
    int l = 0;
    int r = 0;
    int m = 0;
    while (r < pricesSize)
    {
        if (prices[l] < prices[r])
            m = prices[r] - prices[l] > m ? prices[r] - prices[l] : m;
        else
            l = r;
        r++;
    }
    return m;
}

int main(void)
{
}