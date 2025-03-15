#include <iostream>

int main()
{
   int k, n, w;
   std::cin >> k >> n >> w;

   int r = k * w * (w + 1) / 2;
   std::cout << std::max(0, r - n);
}

/*
1 2 3 4 5 6 7

(7 * (7 + 1)) / 2

*/