#include <iostream>
#include <vector>
using namespace std;

void merge_sort(vector<int> &arr)
{
   if(arr.size() < 2) return;
   vector<int> left(arr.begin(), arr.begin() + arr.size() / 2);
   vector<int> right(arr.begin() + arr.size() / 2, arr.end());
   merge_sort(left);
   merge_sort(right);

   int i = 0;
   int j = 0;
   int k = 0;
   while(i < left.size() && j < right.size())
   {
      if(left[i] < right[j]) arr[k++] = left[i++];
      else arr[k++] = right[j++];
   }
   while(i < left.size()) arr[k++] = left[i++];
   while(j < right.size()) arr[k++] = right[j++];
}

int main(void)
{
   vector<int> arr = {1, 3, 5, 1, 7, 4, 4, 4, 0, 2, 6, 0};
   for(int e : arr) cout << e << " ";
   cout << endl;

   merge_sort(arr);
   for(int e : arr) cout << e << " ";
   cout << endl;
}