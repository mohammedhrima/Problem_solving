#include <iostream>

/*
0 time, save

*/

int main()
{
    int T, X, A, B;
    std::cin >> T >> X >> A;
    std::cout << 0 << " " << A << std::endl;
    for(int i = 1; i < T + 1; i++)
    {
        std::cin >> B;
        if(std::abs(A - B) >= X)
        {
            std::cout << i << " " << B << std::endl;
            A = B;
        }
    }
}