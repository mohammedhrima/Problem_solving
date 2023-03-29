#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N;
    scanf("%d", &N);
    int *A = calloc(N, sizeof(int));
    int M = N;

    for (int i = 0; i < N; i++)
    {
        int a;
        scanf("%d", &a);
        if (A[a - 1] == 0 && A[i] == 0)
        {
            M--;
            //printf("put 1 in index %d\n", a - 1);
            A[a - 1] = 1;
        }
    }
    printf("%d\n", M);
    int i = 0;
    while (i < N)
    {
        if(A[i] == 0)
            printf("%d ", i + 1);
        i++;
    }
    // printf("\n");
}