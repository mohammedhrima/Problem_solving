#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> &arr, int l, int r, int to_find)
{
   while (l < r)
   {
      int mid = l + (r - l) / 2;
      if (arr[mid] == to_find) return mid;
      else if (to_find < arr[mid]) r = mid;
      else l = mid + 1;
   }
   return -1;
}

int main()
{
   vector<int> arr = {1, 3, 5, 7};
   int to_find = 4;
   int r = binary_search(arr, 0, arr.size(), to_find);
   cout << r << endl;
}