#include <iostream>
#include <stdbool.h>
#include <cstring>
using namespace std;
/*
S has length 8
S has 1K 1Q 2R 2B N

condition:
    x < y , S[x]='B' S[y]='B', (x%2=0 && y%2=1) || (x%2=1 && y%2=0)
    'R' < 'K' < 'R'
*/

int table[255];
bool function(string str)
{
    for (int i = 0; i < 8; i++)
    {
        if (strchr("BK", str[i]))
            table[str[i]] += i;
        if (str[i] == 'R')
            table['K'] == 0 ? table['R'] += 1 : table['R'] -= 1;
    }
    return (table['B'] % 2 != 0 && table['R'] == 0);
}

int main(void)
{
    string str;
    cin >> str;

    cout << (function(str) ? "Yes" : "No") << endl;
}