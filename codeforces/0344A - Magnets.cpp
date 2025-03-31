#include <iostream>

int main()
{
   int n;
   int r = 0;

   std::cin >> n;
   int a = 0;
   while(n)
   {
      int c;
      std::cin >> c;
      if(c != a) r++;
      a = c; 
      n--;
   }
   std::cout << r << std::endl;
}