#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

bool isIsomorphic(char *s, char *t)
{
    int i = 0;
    char hash1[255] = {0};
    char hash2[255] = {0};

    while (s[i])
    {
        if (hash1[s[i]] && hash1[s[i]] != t[i])
            return false;
        if (hash2[t[i]] && hash2[t[i]] != s[i])
            return false;
        hash1[s[i]] = t[i];
        hash2[t[i]] = s[i];
        i++;
    }
    return true;
}

int main()
{
    struct
    {
        char *s;
        char *t;
        bool res;
    } v[] = {
        {"egg", "add", 1},
        {"foo", "bar", 0},
        {"paper", "title", 1},
        {"badc", "baba", 0},
        {0, 0}};
    for (int i = 0; v[i].s; i++)
        printf("%d\n", isIsomorphic(v[i].s, v[i].t) == v[i].res);
}