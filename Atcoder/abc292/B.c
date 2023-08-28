#include <stdio.h>
#include <stdlib.h>

/*
    N players
    Q events
    removerd if:
        2 yellow
        1 red card
    events:
        1: yellow
        2: red
        3: asked if player is removed

    1 <= N <= 100
    1 <= Q <= 100
    1 <= x <= N events

*/

int main(void)
{
    int N, Q;

    scanf("%d %d", &N, &Q);
    int *Players = calloc(N, sizeof(int));
    int event;
    int Player;
    for (int i = 0; i < Q; i++)
    {
        scanf("%d %d", &event, &Player);
        if (event != 3)
        {
            Players[Player - 1] += event;
        }
        else
        {
            if (Players[Player - 1] >= 2)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
}