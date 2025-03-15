#include <iostream>

int main()
{
   int n;
   std::cin >> n;
   bool easy = true;
   while(n)
   {
      int i = 0;
      std::cin >> i;
      if(i) easy = false;
      n--;
   }
   if(easy)
      std::cout << "EASY" << std::endl;
   else
      std::cout << "HARD" << std::endl;
}