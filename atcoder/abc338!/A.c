#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[101];
    memset(str, 0, sizeof(str));
    scanf("%s", str);
    int i = 0;
    if (!isupper(str[i++]))
    {
        printf("No\n");
        return 0;
    }

    while (islower(str[i]))
        i++;
    if (str[i])
        printf("No\n");
    else
        printf("Yes\n");
}