#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *S;
    S = calloc(100, sizeof(char));
    scanf("%s", S);
    int len = strlen(S);
    int i = 0;
    while (i < len)
    {
        printf("%c", S[i + 1]);
        printf("%c", S[i]);
        i += 2;
    }

    // printf("%s\n", S);
}