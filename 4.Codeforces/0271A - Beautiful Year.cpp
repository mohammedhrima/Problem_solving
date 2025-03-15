#include <iostream>
#include <string>
#include <map>
#include <cmath>

int find(int n)
{
   std::string str = std::to_string(n);
   std::map<char, int> digits;
   for (int i = str.length() - 1; i >= 0; i--)
   {
      if (digits.count(str[i])) return digits[str[i]] - '0';
      digits[str[i]] = str.length() - i - 1;
   }
   return -1;
}

int main()
{
   int n;
   std::cin >> n;
   n++;
   int r;
   while ((r = find(n)) >= 0)
   {
      // std::cout << n << std::endl;
      n += (int)std::pow(10, r);
   }
   std::cout << n << std::endl;
}