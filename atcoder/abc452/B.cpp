#include <iostream>

/*
H, W

*/
int main()
{
    int H, W;
    std::cin >> H >> W;

    for(int y = 0; y < H; y++)
    {
        std::string s;
        if (y == 0 || y == H - 1)
           s = std::string(W, '#');
        else
        {
            s = std::string(W, '.');
            s[0] = '#';
            s[W - 1] = '#';
        }
        std::cout << s << std::endl;
    }
}