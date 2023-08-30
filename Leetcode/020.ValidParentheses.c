#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char *s)
{
    int i = 0;
    int j = 0;
    char *stack = calloc(strlen(s) + 1, sizeof(char));

    while (s[i])
    {
        if (strchr("({[", s[i]))
        {
            printf("found left '%c'\n", s[i]);
            stack[j++] = s[i++];
            printf("stack now: '%s'\n", stack);
        }
        else
        {
            j--;
            if (j < 0)
                return false;
            if (s[i] == '}' && stack[j] != '{')
                return false;
            if (s[i] == ']' && stack[j] != '[')
                return false;
            if (s[i] == ')' && stack[j] != '(')
                return false;
            i++;
        }
    }
    if(j) return false;
    return true;
}

int main(void)
{
    // isValid("((((");
    printf("-> %d\n", isValid("{[]"));
}