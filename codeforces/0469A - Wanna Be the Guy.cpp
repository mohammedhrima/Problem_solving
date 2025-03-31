#include <iostream>
#include <set>

int main()
{
    int n;
    std::set<int> s;
    std::cin >> n;

    int x, y, i = 3;
    while(--i)
    {
        std::cin >> x;
        while (x)
        {
            std::cin >> y;
            s.insert(y);
            x--;
        }
    }
    std::cout << (s.size() == n ? "I become the guy." : "Oh, my keyboard!") << std::endl;
}