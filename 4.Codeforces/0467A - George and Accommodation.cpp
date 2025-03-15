#include <iostream>

int main()
{
   int n;
   int r = 0;
   std::cin >> n;

   while (n)
   {
      int p, q;
      std::cin >> p >> q;
      if (q - p > 1)
         r++;
      n--;
   }
   std::cout << r << std::endl;
}