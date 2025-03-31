#include <stdio.h>

int main(void)
{
    char str[100];

    scanf("%s", str);

    int i = 0;
    while (str && str[i])
        printf("%c", str[i++] - 'a' + 'A');
}