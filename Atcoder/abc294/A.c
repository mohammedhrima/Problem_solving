#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N;
    scanf("%d", &N);
    int *A = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        scanf("%d", A + i);

    for (int i = 0; i < N; i++)
        A[i] % 2 == 0 && printf("%d ", A[i])
    
    
}