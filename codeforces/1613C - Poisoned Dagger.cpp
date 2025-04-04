#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool dragon_died(vector<long long> attacks, long long d, long long damage_needed)
{
   long long total_damage = 0;
   long long last_end = 0;

   for (auto attack : attacks)
   {
      long long next_end = attack + d - 1;
      if (last_end < attack)
         total_damage += d;
      else
         total_damage += next_end - last_end;
      last_end = next_end;
      if (total_damage >= damage_needed)
         return true;
   }
   return total_damage >= damage_needed;
}

long long duration()
{
   long long attacks_size, damage_needed;
   cin >> attacks_size >> damage_needed;
   vector<long long> attacks(attacks_size);
   for (auto &e : attacks)
      cin >> e;

   sort(attacks.begin(), attacks.end());
   long long l = 1, r = damage_needed, res = damage_needed;
   while (l <= r)
   {
      long long d = l + (r - l) / 2;
      if (dragon_died(attacks, d, damage_needed))
      {
         res = d;
         r = d - 1;
      }
      else
         l = d + 1;
   }
   return res;
}

int main()
{
   int i;
   cin >> i;
   vector<long long> res;
   while (i--)
      cout << duration() << endl;
   return 0;
}