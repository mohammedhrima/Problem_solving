#include <iostream>

int main()
{
    int n; 
    std::string s;

    std::cin >> n;
    std::cin >> s;

    size_t p = 0;
    while(p < s.length() && s[p] == 'o') p++;
    std::cout << (p == s.length() ? "" : p > 0 ? s.substr(p) : s) << std::endl;
}