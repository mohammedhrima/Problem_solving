#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

void mergeInsertion(std::vector<int> &v)
{
    size_t len = v.size();
    if (len >= 8)
    {
        size_t i = 0;
        std::vector<int> left;
        std::vector<int> right;
        while (i < len / 2)
            left.push_back(v[i++]);
        while (i < len)
            right.push_back(v[i++]);
        // recursion
        mergeInsertion(left);
        mergeInsertion(right);
        // merge
        i = 0;
        size_t j = 0;
        size_t k = 0;
        while (i < len / 2 && j < len / 2 + len % 2)
            v[k++] = left[i] < right[j] ? left[i++] : right[j++];
        while (i < len / 2)
            v[k++] = left[i++];
        while (j < len / 2 + len % 2)
            v[k++] = right[j++];
    }
    else if (len >= 2)
    {
        // insertion
        for (size_t i = 1; i < len; i++)
        {
            int curr = v[i];
            int j = i - 1;
            while (j >= 0 && v[j] > curr)
            {
                v[j + 1] = v[j];
                j--;
            }
            v[j + 1] = curr;
        }
    }
}

int main()
{
    int arr[] = {1, 3, 5, 1, 7, 4, 4, 4, 0, 2, 6, 0};
    std::vector<int> v;
    size_t len = sizeof(arr) / sizeof(arr[0]);
    for (size_t i = 0; i < len; i++)
        v.push_back(arr[i]);

    mergeInsertion(v);
    for (size_t i = 0; i < len; i++)
        std::cout << v[i] << " ";
    std::cout << "\n";

    return 0;
}