#include <iostream>
#include <algorithm>

int main()
{
   std::string str1, str2;

   std::cin >> str1;
   std::cin >> str2;
   std::reverse(str2.begin(), str2.end());

   if (str1 == str2)
      std::cout << "YES" << std::endl;
   else
      std::cout << "NO" << std::endl;
}