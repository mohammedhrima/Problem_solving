#include <stdio.h>
#include <stdbool.h>

int main()
{
    char str[101] = {0};
    bool cmp[255] = {0};
    scanf("%s", str);
    int i = 0;
    int j = 0;
    while (i < str[i])
    {
        if (!cmp[str[i]])
        {
            cmp[str[i]] = 1;
            j++;
        }
        i++;
    }
    if (j % 2 == 0)
        printf("CHAT WITH HER!\n");
    else
        printf("IGNORE HIM!\n");
}
