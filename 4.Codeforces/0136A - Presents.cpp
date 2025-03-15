#include <iostream>
#include <vector>

int main()
{
   int n;
   std::cin >> n;

   std::vector<int> p(n + 1);
   for (int i = 1; i <= n; i++)
      std::cin >> p[i];

   std::vector<int> q(n + 1);
   for (int i = 1; i <= n; i++)
      q[p[i]] = i;
   for (int i = 1; i <= n; i++)
      std::cout << q[i] << " ";
   std::cout << std::endl;
};