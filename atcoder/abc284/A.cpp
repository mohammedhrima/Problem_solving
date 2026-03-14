#include <iostream>
#include <vector>

int main()
{
    int N;
    std::vector<std::string> strs;

    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::string str;
        std::cin >> str;

        strs.push_back(str);
    }
    for (int i = strs.size() - 1; i >= 0; i--)
        std::cout << strs[i] << std::endl;
}