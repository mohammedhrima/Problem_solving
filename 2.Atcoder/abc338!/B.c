#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void mergeSort(char *string, int len)
{
    if (len >= 2)
    {
        char *left = (char*)calloc(len / 2 + 1, 1);
        char *right = (char*)calloc(len / 2 + len % 2 + 1, 1);
        memcpy(left, string, (len / 2));
        memcpy(right, string + len / 2, (len / 2 + len % 2));
        // recursion
        mergeSort(left, len / 2);
        mergeSort(right, len / 2 + len % 2);
        // merge
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < len / 2 && j < len / 2 + len % 2)
            string[k++] = left[i] < right[j] ? left[i++] : right[j++];
        while (i < len / 2)
            string[k++] = left[i++];
        while (j < len / 2 + len % 2)
            string[k++] = right[j++];
        free(left);
        free(right);
    }
}

int main(void)
{
    char str[1000];
    memset(str, 0, sizeof(str));
    scanf("%s", str);
    mergeSort(str, strlen(str));
    int i = 0;
    char c = str[0];
    int l = 0;
    while (str[i])
    {
        int j = i + 1;
        while (str[i] == str[j])
            j++;
        if (j - i > l)
        {
            l = j - i;
            c = str[i];
        }
        i++;
    }
    printf("%c\n", c);
}