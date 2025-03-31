#include <iostream>

/*

string . | *
2 |
1 *

in if | * | else out


*/

int main(void)
{
    std::string s;
    int n;
    std::cin >> n;
    s = new char[n + 1];
    std::cin >> s;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        if ((x == 0 || x == 2) && s[i] == '|')
            x++;
        else if (x == 1 && s[i] == '*')
            x++;
    }
    if (x == 3)
        std::cout << "in" << std::endl;
    else
        std::cout << "out" << std::endl;
}