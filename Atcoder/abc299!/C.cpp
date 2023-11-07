#include <iostream>
#include <string>

/*
string of len L+1
contains only o -
first and last char are -
and the others o


*/

int main(void)
{
    int n;
    std::string str;
    std::cin >> n;
    std::cin >> str;
    int g = -1;
#if 0
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '-')
        {
            if (i - l > g)
                g = i - l;
            l = i;
        }
    }
#else
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '-')
        {
            int e = i + 1;
            while (e < n && str[e] != '-')
                e++;
            if (str[e] == '-')
            {
                if (e - i > g)
                    g = e - i;
            }
        }
    }
#endif
    std::cout << g - 1 << std::endl;
}