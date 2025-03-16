#include <iostream>
#include <vector>

int main()
{
    int n;
    std::string str;
    std::cin >> n >> str;

    if (n < 26)
    {
        std::cout << "NO" << std::endl;
        return 0;
    }
    std::vector<bool> seen(26, false);
    for (int i = 0; i < n; i++)
        if (isalpha(str[i]))
            seen[tolower(str[i]) - 'a'] = true;
    bool isPangram = true;
    for (bool letterSeen : seen)
        if (!letterSeen)
        {
            isPangram = false;
            break;
        }
    std::cout << (isPangram ? "YES" : "NO") << std::endl;
}