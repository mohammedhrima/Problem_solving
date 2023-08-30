#include <stdio.h>
#include <string.h>
#include <ctype.h>

int lengthOfLastWord(char * s){
    int i;
    int end;

    if(s == NULL) return i;
    i = strlen(s) - 1;
    while(i >= 0 && isspace(s[i]))
        i--;
    end = i;
    while(i >= 0 && !isspace(s[i]))
        i--;
    return end - i;
}

int main(void)
{
    printf("%d\n", lengthOfLastWord("Hello World"));
    printf("%d\n", lengthOfLastWord("   fly me   to   the moon  "));
    printf("%d\n", lengthOfLastWord("luffy is still joyboy"));
    printf("%d\n", lengthOfLastWord("a"));
}