#include <iostream>

/*
1 <= a, b <= 15


*/

int main()
{
    int a, b;

    std::cin >> a >> b;

    bool r = (a / b == 2) || (b / a == 2);
    std::cout << (r ? "Yes" : "No") << std::endl;
}