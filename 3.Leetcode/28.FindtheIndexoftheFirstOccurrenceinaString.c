#include <string.h>

int strStr(char * haystack, char * needle){
    int i = 0;

    if(haystack == NULL || needle == NULL)
        return 0;
    while(haystack[i])
    {
        if(strncmp(haystack + i, needle, strlen(needle)) == 0)
            return i;
        i++;
    }
    return -1;
}

int main(void)
{
    printf("%d\n", strStr("sadbutsad", "sad"));
    printf("%d\n", strStr("leetcode", "leeto"));
    // printf("%d\n", strStr("sadbutsad", "sad"));

}

