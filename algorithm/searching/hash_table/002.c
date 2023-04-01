#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define TABLE_SIZE 100000

// Hash table data structure
typedef struct
{
    int key;
    bool value;
} HashTable;

// Hash function
int hash(int key)
{
    return abs(key) % TABLE_SIZE;
}

// Insert key into hash table
void insert(HashTable *table, int key)
{
    int index = hash(key);
    while (table[index].value == true && table[index].key != key)
    {
        index = (index + 1) % TABLE_SIZE;
    }
    table[index].key = key;
    table[index].value = true;
}

// Check if key is in hash table
bool contains(HashTable *table, int key)
{
    int index = hash(key);
    while (table[index].value != false)
    {
        if (table[index].key == key)
        {
            return true;
        }
        index = (index + 1) % TABLE_SIZE;
    }
    return false;
}

// Check if list contains two numbers that add up to 6
bool has_sum_of_6(int nums[], int size)
{
    HashTable table[TABLE_SIZE] = {0};
    for (int i = 0; i < size; i++)
    {
        int diff = 6 - nums[i];
        if (contains(table, diff))
        {
            return true;
        }
        insert(table, nums[i]);
    }
    return false;
}

// Example usage
int main()
{
    printf("%d\n", abs(-7));
    int nums[] = {-1,7, 3, 4, 301, 5};
    int size = sizeof(nums) / sizeof(int);
    if (has_sum_of_6(nums, size))
    {
        printf("The list contains two numbers that add up to 6\n");
    }
    else
    {
        printf("The list does not contain two numbers that add up to 6\n");
    }
    return 0;
}

