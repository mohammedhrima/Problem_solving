#include <stdint.h>
#include <stdio.h>

uint32_t reverseBits(uint32_t n)
{
    uint32_t m = 0;
    int shift = 0;
    int len = 32;
    while (shift < len)
    {
        m = m | (n & 1);
        n = n >> 1;
        shift++;
        if(shift < len)
            m = m << 1;
    }
    return m;
}

// 01000000
int main(void)
{
    uint32_t x = reverseBits(43261596);
    printf("%d\n", (int)x);
}