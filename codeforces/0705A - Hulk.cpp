#include <iostream>

/*
hate, love, hate ...

*/
int main()
{
    int n;
    std::cin >> n;
    int i = 0;
    std::string str;
    while(i < n)
    {
        str += "I ";
        str += (i % 2 ? "love" : "hate");
        i++;
        str += (i < n ? " that " : " it");
    }
    std::cout << str << std::endl;
}