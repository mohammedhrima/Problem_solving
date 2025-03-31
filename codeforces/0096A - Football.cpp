#include <iostream>

int main()
{
   std::string str;

   std::cin >> str;
   int l = 0;
   int r = 1;
   bool dang = false;
   while(r < str.length())
   {
      while(str[r] == str[l]) r++;
      if(r - l >= 7) dang = true;
      l = r;
      r++;
   }
   std::cout << (dang ? "YES" : "NO") << std::endl;
}