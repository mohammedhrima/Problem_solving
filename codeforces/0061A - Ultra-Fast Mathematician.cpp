#include <iostream>

/*
10**8 numbers in sec

230 AD
pairs of numbers 0, 1

*/

int main()
{
    std::string str1;
    std::string str2;
    std::cin >> str1;
    std::cin >> str2;
    for(int i = 0; i < str1.length(); i++)
    {
        if(str1[i] == str2[i]) str1[i] = '0';
        else str1[i] = '1';
    }
    std::cout << str1 << std::endl;
}