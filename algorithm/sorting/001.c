#include <stdio.h>

int main(void)
{
    int list[] = {12, 2, 0, -2, 3, 45, 98, 6};
    int len = (int)sizeof(list) / sizeof(int);
    int i = 0;
    int N = 0;
#if 1
    while (i < len)
    {
        int j = i;
        while (j < len)
        {
            if (list[i] > list[j])
            {
                int tmp = list[i];
                list[i] = list[j];
                list[j] = tmp;
            }
            N++;
            j++;
        }
        i++;
    }
#else
    while (i < len - 1)
    {
        if (list[i] > list[i + 1])
        {
            int tmp = list[i];
            list[i] = list[i + 1];
            list[i + 1] = tmp;
            i = -1;
        }
        N++;
        i++;
    }
#endif
    i = 0;
    for (int i = 0; i < len; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
    printf("N: %d\n", N);
}