#include <iostream>
#include <bits/stdc++.h>
/*
n drinks
i from 0 to n
p0, p1 ... (fraction)

*/

int main()
{
   int n, a[101];
   std::cin >> n;
   double ans = 0, sum = 0;
   for (int i = 0; i < n; i++)
   {
      std::cin >> a[i];
      sum += a[i];
   }
   ans = sum / n;
   std::cout << std::fixed << std::setprecision(12) << ans << std::endl;
}