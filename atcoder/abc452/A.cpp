#include <iostream>
#include <map>

int main()
{
    std::map<int, int> arr = {
        {1, 7},
        {3, 3},
        {5, 5},
        {7, 7},
        {9, 9},
    };
    int M, D;
    std::cin >> M >> D;
    auto it = arr.find(M);
    if (it == arr.end() || it->second != D)
    {
        std::cout << "No" << std::endl;
        return 0;
    }
    std::cout << "Yes" << std::endl;
}