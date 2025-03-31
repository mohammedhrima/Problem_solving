#include <iostream>
#include <cmath>

/*
a b  , a <= b, a * 3,  b * 2

a * 3**x > b * 2**x
(3 / 2)**x > b / a
x * ln(3/2) > ln(b/a)
x > ln(b/a) / ln(3/2)

*/

int main()
{
   int a, b;
   int r = 0;
   std::cin >> a >> b;
#if 0
   while(a <= b)
   {
      a *= 3;
      b *= 2;
      r++;
   }
#else
   double x = std::log(static_cast<double>(b) / a) / std::log(3.0 / 2.0);
   r = std::floor(x) + 1;
#endif
   std::cout << r << std::endl;
}