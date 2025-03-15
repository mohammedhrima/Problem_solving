#include <iostream>
#include <string>
using namespace std;

int main()
{
   int n;
   string s;
   cin >> n >> s;
   int r = 0;
   for (int i = 1; i < n; i++)
      if (s[i - 1] == s[i]) r++;
   cout << r;
   return 0;
}