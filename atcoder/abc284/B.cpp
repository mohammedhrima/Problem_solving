#include <iostream>

int main()
{
    int T;

    std::cin >> T;

    for (int i = 0; i < T; i++)
    {
        int N;
        std::cin >> N;
        int r = 0;

        for (int j = 0; j < N; j++)
        {
            int c;
            std::cin >> c;
            r += (c % 2);
        }
        std::cout << r << std::endl;
    }
    
}