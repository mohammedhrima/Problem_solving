/*
N
S of length N
o good
- fair
x poor

at least one good
no interviewr is poor
*/
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
    int N;
    char *str;
    scanf("%d", &N);
    str = calloc(N + 1, sizeof(char));
    scanf("%s", str);
    int good = 0;
    int poor = 0;
    for(int i = 0; str[i]; i++)
    {
        if(str[i] == 'x')
        {
            free(str);
            printf("No\n");
            return 0;
        }
        if(str[i] == 'o')
            good = 1;
    }
    good ? printf("Yes\n") : printf("No\n");
    free(str);
}

