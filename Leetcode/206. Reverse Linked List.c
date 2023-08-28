#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *new_list = NULL;
    while(head)
    {
        struct ListNode *tmp = head->next;
        head->next = new_list;
        new_list = head;
        head = tmp;
    }
    return new_list;
}

struct ListNode *new_node(int val)
{
    struct ListNode *new = calloc(1, sizeof(struct ListNode));
    new->val = val;
    return new;
}

struct ListNode *init_list(int len)
{
    int i = 0;
    struct ListNode *new = new_node(i++);
    struct ListNode *head = new;
    while(i < len)
    {
        new->next = new_node(i++);
        new = new->next;
    }
    return head;
}

int main()
{
    struct ListNode *head = init_list(5);
    head = reverseList(head);
    int i = 0;
    while(i < 5)
    {
        printf("-> %d\n", head->val);
        head = head->next;
        i++;
    }
}