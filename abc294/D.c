#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, Q;
    scanf("%d %d", &N, &Q);

    int called[N];
    int called_count = 0;
    int last = 0;

    for (int i = 0; i < Q; i++)
    {
        int event;
        scanf("%d", &event);
        if (event == 1)
            called[called_count++] = ++last;
        else if (event == 2)
        {
            int x;
            scanf("%d", &x);
            for (int j = 0; j < called_count; j++)
            {
                if (called[j] == x)
                {
                    called_count--;
                    for (int k = j; k < called_count; k++)
                        called[k] = called[k + 1];
                    break;
                }
            }
        }
        else
        {
            printf("%d\n", called[0]);
        }
    }
    return 0;
}
