#include <iostream>

/*
1 -> n stops
ai exist
bi enter

everyone exit at n stop

*/

int main()
{
   int i;
   std::cin >> i;

   int r = 0;
   int m = 0;
   while(i)
   {
      int a, b;
      std::cin >> a >> b;
      r -= a;
      r += b;
      m = std::max(m, r);
      i--;
   }
   std::cout << m << std::endl;

}