#include <ctype.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int myAtoi(char *s)
{
    if (s == NULL)
        return 0;
    int i = 0;
    long res = 0;
    int sign = 1;
    while (isspace(s[i]))
        i++;
    if (s[i] && strchr("+-",s[i]))
    {
        if(s[i] == '-')
            sign = -1;
        i++;
    }
    while (isdigit(s[i]))
    {
        res = 10 * res + s[i] - '0';
        if (sign == -1 && res > 2147483648)
            return 2147483648;
        else if (sign == 1 && res > 2147483647)
            return 2147483647;
        i++;
    }
    return sign * res;
}
//  [-2147483648 to 2147483647]
int main(void)
{
    printf("%d\n", myAtoi("21474836460"));
}