#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool isAnagram(char *s, char *t)
{
    int *str = calloc(255, sizeof(int));
    int i = 0;
    while (s[i])
    {
        str[s[i]] += 1;
        i++;
    }
    i = 0;
    while (t[i])
    {
        str[t[i]] -= 1;
        if(str[t[i]] < 0)
            break;
        i++;
    }
    i = 0;
    while (i < 255)
    {
        if (str[i] != 0)
        {
            free(str);
            return false;
        }
        i++;
    }
    free(str);
    return (true);
}

#include <stdio.h>
int main(void)
{
    printf("%d\n", isAnagram("anagram", "nagaram"));
}