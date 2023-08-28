#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *longestCommonPrefix(char **strs, int strsSize)
{
    int i = 0;
    int j = 0;

    char c = strs[i][j];
    while (i < strsSize)
    {
        if (strs[i][j] != c || strs[i][j] == '\0')
            break;
        i++;
        if (i == strsSize)
        {
            i = 0;
            j++;
            c = strs[i][j];
        }
    }
    if(j)
    {
        char *res = calloc(j + 1, sizeof(char));
        strncpy(res, strs[0], j);
        return res;
    }
    return "";
}
