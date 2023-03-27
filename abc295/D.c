#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 500000

char *sort(char *str)
{
    int i = 0;
    int len = strlen(str);
    char tmp;
    while (i < len)
    {
        int j = i;
        while (j < len)
        {
            if (str[i] > str[j])
            {
                tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
            j++;
        }
        i++;
    }
    return(str);
}

int main(void)
{
    char str[MAX];

    scanf("%s", str);
    int res = 0;

    int len = strlen(str);
    
    printf("-> %d\n", res);
}