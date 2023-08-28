/*
NxN matrix

*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *table;
    int *tmp;
    int N;
    scanf("%d", &N);
    table = calloc(N * N, sizeof(int *));
    tmp = calloc(N * N, sizeof(int *));

    for (int i = 0; i < N * N; i++)
        scanf("%d", &(table[i]));
    for (int i = 0; i < N * N; i++)
    {
        // tmp[];
        if (i % N == 0)
            printf("\n");
        printf("%d ", table[i]);
    }
    for (int i = 0; i < N * N; i++)
    {
        if (i % N == 0)
            printf("\n");
        printf("%d ", table[i]);
    }
}