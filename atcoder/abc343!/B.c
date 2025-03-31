#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*
3
2 1 3
3
2 3
1 2
1 3

3 Persons
P1 -> 2
P2 -> 1
P3 -> 3

P2 P1 P3



*/

int main(void)
{
#if 0
    int arr1[] = {2, 1, 3};
    int len = sizeof(arr1) / sizeof(int);
    int *arr2 = calloc(len + 1, sizeof(int));
    int i = 0;
    while (i < len)
    {
        arr2[arr1[i] - 1] = i + 1;
        printf("%d ", arr1[i]);
        i++;
    }
    printf("\n");
    i = 0;
    while (i < len)
    {
        printf("%d ", arr2[i]);
        i++;
    }
    free(arr2);
    printf("\n");
#else
    int N, *P, T, Q, *R;

    scanf("%d", &N);
    P = calloc(N, sizeof(int));
    int i = 0;
    while (i < N)
    {
        scanf("%d", &T);
        P[T - 1] = i + 1;
        i++;
    }
    i = 0;
    while (i < N)
    {
        printf("%d ", P[i]);
        i++;
    }
    printf("\n");

    // i = 0;
    // scanf("%d", &Q);
    // R = calloc(Q * 2, sizeof(int));
    // i = 0;
    // while (i < Q * 2)
    // {
    //     scanf("%d", &R[i++]);
    //     scanf("%d", &R[i++]);
    // }
    // i = 0;
    // while (i < Q * 2)
    // {
    //     printf("%d\n", abs(R[i] - R[i + 1]));
    //     i += 2;
    // }
    // printf("\n");

    free(P);
#endif
}

/*
3 7 2 1 6 5 4
4 3 1 7 6 5 2




*/