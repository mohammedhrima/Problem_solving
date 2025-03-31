#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int>&arr)
{
   for(int i = 1; i < arr.size(); i++)
   {
      int curr = arr[i];
      int j = i - 1;
      while(j >= 0 && arr[j] > curr)
      {
         arr[j + 1] = arr[j];
         j--;
      }
      arr[j + 1] = curr;
   }
}

int main()
{
 vector<int> arr = {1, 3, 5, 1, 7, 4, 4, 4, 0, 2, 6, 0};
   for(int e : arr) cout << e << " ";
   cout << endl;

   insertion_sort(arr);
   for(int e : arr) cout << e << " ";
   cout << endl;
}