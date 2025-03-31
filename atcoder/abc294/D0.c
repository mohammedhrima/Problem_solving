#include <stdio.h>
#include <stdlib.h>
/*
N people with ID 1,2,....N
Q events:
    1  : Teller calls the person with smallest ID / for the first time
    2 x: Person with ID = x comes to teller for 1st time / has already been called at least once
                                                           will come only one time
    3  : Teller calls the person with smallest ID again / has not come
                                                        / event repeated at least one time
    print ID of peoples with events = 3 / Teller called person with smallest ID
1 <= N
2 <= Q
*/
/*
N Q
event1
event2
event3
event4
.
.
.
.
eventQ
*/
/*
i = 1    1   Teller calls 1
i = 2    1   Teller calls 2
i = 3    3   Teller calls 1 again
i = 4    2 1 Person 1 did come
i = 5    1   Teller calls 3
i = 6    2 3 Person 3 did come
i = 7    3   Teller calls 2 again
i = 8    1   Teller calls 4
i = 9    2 2 Person 2 did come
i = 10   3   Teller calss 4 again
*/
int main(void)
{
    int N, Q;
    scanf("%d %d", &N, &Q);
    int *Peoples = calloc(N, sizeof(int));
    int *called_more_than_once = calloc(N, sizeof(int));
    int *event = calloc(Q, sizeof(int));
    int i = 0;
    int j = 0;
    int k = 0;
    for (; i < Q; i++)
    {
        scanf("%d", &event[i]);
        // Teller calls smaller first time
        if (event[i] == 1)
        {
            j = 0;
            while (j < N && Peoples[j] != 0)
                j++;
            // check if never called
            if (Peoples[j] == 0)
            {
                // printf("Teller calls %d \n", j + 1);
                Peoples[j] = 1;
            }
        }
        // Person with ID comes to teller
        // has already been called at least one time
        if (event[i] == 2)
        {
            scanf("%d", &j);
            if (Peoples[j - 1] == 1 || Peoples[j-1] == 3)
            {
                Peoples[j - 1] = 2; // mark as did come
                // printf("Person %d did come\n", j);
            }
        }
        // Teller call Person with smallest ID again
        if (event[i] == 3)
        {
            j = 0;
            while (j < N && Peoples[j] != 1 && Peoples[j] != 3)
                j++;
            // check if it's called at least one time
            if (Peoples[j] == 1 || Peoples[j] == 3)
            {
                Peoples[j] == 3;
                called_more_than_once[k] = j+1;
                k++;
               // printf("Teller calls %d again\n", j + 1);
            }
        }
    }
    // printf("\n");
    i = 0;
    while (i < k)
    {
        printf("%d\n", called_more_than_once[i]);
        i++;
    }
}