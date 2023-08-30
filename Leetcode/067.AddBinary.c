#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void reverse_string(char *string, int len)
{
    int i = 0;

    while (i < len / 2)
    {
        char c = string[len - i - 1];
        string[len - i - 1] = string[i];
        string[i] = c;
        i++;
    }
}

char *addBinary(char *a, char *b)
{
    reverse_string(a, strlen(a));
    reverse_string(b, strlen(b));

    char *res = calloc(strlen(a) > strlen(b) ? strlen(a) + 2 : strlen(b) + 2, sizeof(char));
    size_t i = 0;
    int rest = 0;
    int sum;
    while(i < strlen(a) || i < strlen(b) || rest)
    {
        sum = i < strlen(a) ? (a[i] - '0') : sum;
        sum = i < strlen(b) ? sum + (b[i] - '0') : sum;
        sum = sum + rest;
        res[i] = sum % 2 + '0';
        rest = sum / 2;
        sum = 0;
        i++;
    }
    reverse_string(res, strlen(res));
    return res;
}

int main(void)
{
    char *a = strdup("1011");
    char *b = strdup("0001");
    char *res = addBinary(a, b);

    printf("%s\n", res);
    free(a);
    free(b);
    free(res);
    // int i = 0;
}