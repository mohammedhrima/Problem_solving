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
int N = 0;
void Deep_first_search(int **list, int *visited, int x, int y, int H, int W)
{
    if (x + 1 == H && y + 1 == W)
    {
        N++;
        return;
    }
    if (x < W && y < H)
    {
        int *visited2 = calloc(H * W, sizeof(int));
        if (visited2 == NULL)
            exit(-1);
        memcpy(visited2, visited, H*W * sizeof(int));

        visited2[list[y][x] - 1] = 1;
        if (x + 1 < W && y < H && visited2[list[y][x + 1] - 1] == 0)
        {
            Deep_first_search(list, visited2, x + 1, y, H, W);
        }
        if (y + 1 < H && x < W && visited2[list[y + 1][x] - 1] == 0)
        {
            Deep_first_search(list, visited2, x, y + 1, H, W);
        }
        // free(visited);
    }
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
    int *visited = calloc(H * W, sizeof(int));
    Deep_first_search(A, visited, 0, 0, H, W);
    printf("%d\n", N);
}