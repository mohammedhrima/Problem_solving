#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*
S: string contains lowercase english letters
S len between 3 and 100
*/

int main(void)
{
    char str[101];
    memset(str, 0, sizeof(str));
    scanf("%s", str);
    size_t len = strlen(str);
    size_t i = 0;
    size_t res = 0;
    while (i < len)
    {
        size_t j = 0;
        while (j < len && (str[j] != str[i] || i == j))
            j++;
        if (j == len)
        {
            res = i + 1;
            break;
        }
        i++;
    }
    printf("%zu\n", res);
}