#include <stdio.h>
#include <string.h>

int includes(char *str, char c)
{
    int i = 0;
    while (str && str[i])
    {
        if (str[i] == c)
            return (i);
        i++;
    }
    return (-1);
}

int main(void)
{
    char board[8][8];
    char res[3];
    for (int i = 0; i < 8; i++)
    {
        scanf("%s", board[i]);
        int n = includes(board[i], '*');
        if(n >= 0)
        {
            res[0] = 'a' + n;
            res[1] = 8 - i + '0';
        }
    }
    printf("%s\n", res);
}