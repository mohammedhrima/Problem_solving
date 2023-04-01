/*
N peoples
S string, M male, F female
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *reponse(char *str)
{
    int i = 0;
    int len = strlen(str);
    while (i < len)
    {
        //printf("%d ", i);
        if (str[i] == str[i + 1])
            return "No";
        i++;
    }
    return "Yes";
}

int main(void)
{
    int N;
    char *S;
    scanf("%d", &N);
    S = calloc(N + 1, sizeof(char));
    scanf("%s", S);
    printf("%s\n", reponse(S));
}