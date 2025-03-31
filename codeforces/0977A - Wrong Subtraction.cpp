#include <iostream>

/*
one  digit fine
more not fine

last digit != 0 -> -1
last digit == 0 -> / 10
*/

int main()
{
   int n, k;
   std::cin >> n >> k;

   while(k)
   {
      if(n % 10) n--;
      else n /= 10;
      k--;
   }
   std::cout << n << std::endl;
}