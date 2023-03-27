#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int H, W;
    scanf("%d %d", &H, &W);
    int **A = malloc((H + 1) * sizeof(int *));
    char **B = malloc((H + 1) * sizeof(char *));

    int i;
    for (i = 0; i < H; i++)
    {
        A[i] = malloc((W + 1) * sizeof(int));
        B[i] = calloc((W + 1), sizeof(char));
        memset(B[i], '.', W);
        for (int j = 0; j < W; j++)
            scanf("%d", A[i] + j);
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            //printf("%d ", A[i][j]);
            if (A[i][j] != 0)
                B[i][j] = 'A' + A[i][j] - 1;
        }
        //printf("\n");
    }

    for (int i = 0; i < H; i++)
    {
        printf("%s\n", B[i]);
    }
}