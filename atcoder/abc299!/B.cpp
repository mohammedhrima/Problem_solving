#include <iostream>

/*
N   T
C1  C2  C3  ...
R1  R2  R3  ...

N   player
has IDs     1,2,...,N
has colors  1,2,...,C
has rank    1,2,...,R

if T found  , player with greatest rank is winner from whom played color T
if not found, player with greatest rank is winner

*/

int main(void)
{
    int n, t;
    int *c, *r;
    std::cin >> n >> t;
    c = new int[n + 1];
    r = new int[n + 1];
    for (int i = 0; i < n; i++)
        std::cin >> c[i];
    for (int i = 0; i < n; i++)
        std::cin >> r[i];

    bool found = false;
    int g = 0;
    for (int i = 0; i < n; i++)
    {
        if (!found && c[i] == t)
        {
            found = true;
            g = i;
        }
        else if (!found && r[i] > r[g])
            g = i;
        else if (found && c[i] == t && r[i] > r[g])
            g = i;
    }
    std::cout << g + 1 << std::endl;
    delete[] c;
    delete[] r;
}