#include <iostream>
#include <climits>

int main()
{
    int n;
    std::cin >> n;

    int max_height = 0, min_height = INT_MAX;
    int index_max = 0, index_min = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        if (x > max_height)
        {
            max_height = x;
            index_max = i;
        }
        if (x <= min_height)
        {
            min_height = x;
            index_min = i;
        }
    }
    int r = index_max + (n - 1 - index_min) + ((index_max < index_min) ? 0 : -1);
    std::cout << r << std::endl;
}