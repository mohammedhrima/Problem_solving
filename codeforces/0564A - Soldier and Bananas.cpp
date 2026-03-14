#include <iostream>
#include <vector>

/*
1k, 2k, 4k, ... i*k

n dollars

w bananas

*/

int main()
{
    int k, n, w;
    std::cin >> k >> n >> w;

    int r = 0;
    for(int i = 1; i <= w; i++)
        r += i * k;
    std::cout << (r > n ? r - n : 0) << std::endl; 
}