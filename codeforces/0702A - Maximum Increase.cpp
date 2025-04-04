#include <iostream>
#include <algorithm>

int main()
{
   int n;
   std::cin >> n;

   if (n == 0) {
      std::cout << 0 << std::endl;
      return 0;
   }

   int prev, current;
   std::cin >> prev;

   int max_len = 1;
   int curr_len = 1;

   for (int i = 1; i < n; i++)
   {
      std::cin >> current;
      if (current > prev)
      {
         curr_len++;
         max_len = std::max(max_len, curr_len);
      }
      else curr_len = 1;
      prev = current;
   }

   std::cout << max_len << std::endl;
   return 0;
}