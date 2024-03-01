#include <stdio.h>
#include <stdbool.h>

bool canConstruct(char *ransomNote, char *magazine)
{
    int buff[255] = {0};
    int i = 0;
    while (magazine[i])
        buff[magazine[i++]]++;
    i = 0;
    while (ransomNote[i])
    {
        if(!buff[ransomNote[i]])
            return false;
        else
            buff[ransomNote[i]]--;
        i++;
    }
    return true;    
}

int main()
{
}