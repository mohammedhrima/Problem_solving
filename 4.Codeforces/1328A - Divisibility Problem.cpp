#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        int m = a % b;
        vec.push_back(m ? b - a % b : 0);
    }
    for (int i = 0; i < n; i++)
        std::cout << vec[i] << std::endl;
}