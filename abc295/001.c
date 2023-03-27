#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int height, width;
    scanf("%d %d", &height, &width);

    char grid[height][width + 1]; 
    for (int i = 0; i < height; i++)
        scanf("%s", grid[i]);

    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            if (grid[j][i] >= '0' && grid[j][i] <= '9')
            {
                int power = grid[j][i] - '0';
                grid[j][i] ='.';
                for (int y = 0; y < height; y++)
                {
                    for (int x = 0; x < width; x++)
                    {
                        if (abs(i - x) + abs(j - y) <= power && grid[y][x] == '#')
                            grid[y][x] = '.';
                    }
                }
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        printf("%s\n", grid[i]);
    }

    return 0;
}
