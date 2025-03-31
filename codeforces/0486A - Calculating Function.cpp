#include <iostream>

int main()
{
   long long n = 0;
   std::cin >> n;
   std::cout << (n % 2 ? - ((n + 1) / 2) : ((n + 1) / 2)) << std::endl;
};