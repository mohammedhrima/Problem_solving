#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

bool wordPattern(char *pattern, char *s)
{
    char **arr = calloc(255, sizeof(char *));
    int len = (int)strlen(pattern);
    int i = 0;
    int j = 0;
    while (pattern[i] && s[j])
    {
        int k = j;
        while (s[j] && s[j] != ' ')
            j++;
        if (arr[pattern[i]] == NULL)
        {
            arr[pattern[i]] = calloc(j - k + 1, sizeof(char));
            strncpy(arr[pattern[i]], s + k, j - k);
        }
        else if (strncmp(arr[pattern[i]], s + k, j - k) || j - k != (int)strlen(arr[pattern[i]]))
            return false;
        while (isspace(s[j]))
            j++;
        i++;
        int l = 0;
        while (l < i)
        {
            int m = l + 1;
            while (m < i)
            {
                if (pattern[m] != pattern[l] && strcmp(arr[pattern[m]], arr[pattern[l]]) == 0)
                    return false;
                m++;
            }
            l++;
        }
    }
    if (s[j] || pattern[i])
        return false;
    return true;
}

// int main(void)
// {
//     char *pattern = "abba";
//     char *s = "dog constructor constructo dog";
//     printf("%d\n", wordPattern(pattern, s));
// }