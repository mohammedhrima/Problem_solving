#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
H W
2 <= H, W <= 10
1 <= i <= H
1 <= j <= W

current (1,1)
allowed moves: right or down
target (H,W)
*/
void Deep_first_search(int *visited)
{
}

void expand()
{
    int *visited = calloc(H * W, sizeof(int));
}

int main(void)
{
    int H, W;
    scanf("%d %d", &H, &W);
    int **A = calloc(H, sizeof(int *));

    for (int i = 0; i < H; i++)
    {
        // number should be between 1 and 10
        A[i] = calloc(W, sizeof(int));
        for (int j = 0; j < W; j++)
            scanf("%d", A[i] + j);
    }
    printf("\n");
    // for (int i = 0; i < H; i++)
    // {
    //     for (int j = 0; j < W; j++)
    //         printf("%d ", A[i][j]);
    //     printf("\n");
    // }
    // printf("\n");
}