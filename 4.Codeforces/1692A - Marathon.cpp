#include <iostream>
#include <vector>

int main()
{
   int n;
   std::cin >> n;
   std::vector<int> vec;
   while(n)
   {
      int a;
      std::cin >> a;
      int r = 0;
      int i = 1;
      while(i < 4)
      {
         int b;
         std::cin >> b;
         if(b > a) r++;
         i++;
      }
      vec.push_back(r);
      n--;
   }
   for(int i = 0; i < vec.size(); i++)
      std::cout << vec[i] << std::endl;
}