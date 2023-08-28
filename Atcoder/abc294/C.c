#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int value;
    int index;
} num;

void merge_sort(num *array, int len)
{
    if (len > 1)
    {
        num *left = malloc((len / 2) * sizeof(num));
        num *right = malloc((len / 2 + len % 2) * sizeof(num));
        memcpy(left, array, (len / 2) * sizeof(num));
        memcpy(right, array + len / 2, (len / 2 + len % 2) * sizeof(num));

        merge_sort(left, len / 2);
        merge_sort(right, len / 2 + len % 2);

        int i = 0;
        int j = 0;
        int k = 0;
        while (i < len / 2 && j < len / 2 + len % 2)
        {
            if (left[i].value < right[j].value)
            {
                array[k] = left[i];
                i++;
            }
            else
            {
                array[k] = right[j];
                j++;
            }
            k++;
        }
        while (i < len / 2)
        {
            array[k] = left[i];
            k++;
            i++;
        }
        while (j < len / 2 + len % 2)
        {
            array[k] = right[j];
            k++;
            j++;
        }
        free(left);
        free(right);
    }
}

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    num *array = malloc((N + M) * sizeof(num));
    int *res = malloc((N + M) * sizeof(int));
    int i = 0;
    for (; i < N; i++)
    {
        scanf("%d", &array[i].value);
        array[i].index = i;
    }
    for (; i < N + M; i++)
    {
        scanf("%d", &array[i].value);
        array[i].index = i;
    }

   //for (i = 0; i < N + M; i++)
     //   printf("%d ", array[i].value);
    merge_sort(array, N + M);
    for (i = 0; i < N + M; i++)
        res[array[i].index] = i;
    i = 0;
    for (; i < N; i++)
        printf("%d ", res[i] + 1);
    printf("\n");
    for (; i < N + M; i++)
        printf("%d ", res[i] + 1);
}