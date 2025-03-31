#include <iostream>

/*
n dollars 
1, 5, 20, 100
*/

void inline helper(int &r, int &n, int a)
{
   if(!n) return;
   r += n / a;
   n %= a;
}
int main()
{
   int n;
   std::cin >> n;
   int r = 0;
   helper(r, n, 100);
   helper(r, n, 20);
   helper(r, n, 10);
   helper(r, n, 5);
   helper(r, n, 1);
   std::cout << r << std::endl;
}