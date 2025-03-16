#include <iostream>

/*
k punches
l tail shut
m pawn trampled
n threatened

d sufferred

*/

int main()
{
    int i = 0;
    int sum = 0;

    int x = 0;
    while(i < 4)
    {
        std::cin >> x;
        sum += x;
        i++;
    }
    std::cout << "sum: " << sum << std::endl;
    std::cin >> x;
    x -= sum;
    std::cout <<"x: " << x << std::endl;
}