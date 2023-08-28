#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool isPalindrome(char *s)
{
    char *str = calloc(strlen(s) + 1, sizeof(char));
    int i = 0;
    int j = 0;
    while (s[i])
    {
        if (isalnum(s[i]))
        {
            str[j] = isalpha(s[i]) ? tolower(s[i]) : s[i];
            j++;
        }
        i++;
    }
    i = 0;
    int len = strlen(str);
    while (i < len / 2)
    {
        if (str[i] != str[len - i - 1])
        {
            free(str);
            return false;
        }
        i++;
    }
    free(str);
    return true;
}
#include <stdio.h>
int main(void)
{
    printf("%d\n", isPalindrome("0P"));
}