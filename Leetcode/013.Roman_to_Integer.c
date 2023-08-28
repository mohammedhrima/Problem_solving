#include <stdio.h>
#include <string.h>

int rommanToInt(char *s)
{
    int table['X' + 1] = {
        ['I'] = 1,
        ['V'] = 5,
        ['X'] = 10,
        ['L'] = 50,
        ['C'] = 100,
        ['D'] = 500,
        ['M'] = 1000,
    };
    int res = 0;
    for(int i = 0; s[i]; i++)
    {
        if(table[s[i]] < table[s[i + 1]])
            res -= table[s[i]];
        else
            res += table[s[i]];
    }
    return res;
}

int main(void)
{
    printf("-> %d\n",rommanToInt("MCMXCIV"));
}