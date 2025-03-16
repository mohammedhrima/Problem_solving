#include <iostream>
#include <set>

int main()
{
    std::set<int> s;
    for (int i = 0; i < 4; i++)
    {
        int n = 0;
        std::cin >> n;
        s.insert(n);
    }
    std::cout << 4 - s.size() << std::endl;
}