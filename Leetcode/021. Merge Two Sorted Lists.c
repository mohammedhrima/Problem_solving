#include <stdlib.h>
#include <stdio.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} Node;


Node *new_node(int val)
{
    Node *new = calloc(1, sizeof(Node));
    new->val = val;
    return new;
}

Node *init_node(int *array, int len)
{
    int i = 1;
    if(len == 0) return NULL;
    Node *curr = new_node(array[0]);
    Node *head = curr;
    while (i < len)
    {
        curr->next = new_node(array[i]);
        curr = curr->next;
        i++;
    }
    return head;
}

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode head;
    struct ListNode *ptr;

    if(list1 == NULL)
        return list2;
    if(list2 == NULL)
        return list1;
    ptr = &head;
    while(list1 && list2)
    { 
        if(list1->val <= list2->val)
        {
            ptr->next = list1;
            list1 = list1->next;
        }
        else
        {
            ptr->next = list2;
            list2 = list2->next;
        }
        ptr = ptr->next;
    }
    if(list1) ptr->next = list1;
    if(list2) ptr->next = list2;
    return head.next;
}

int main(void)
{
    Node *left = NULL;
    Node *right = NULL;
    left = init_node((int[]){}, 0);
    right = init_node((int[]){}, 0);

    Node *res = mergeTwoLists(left, right);
    while (res)
    {
        printf("%d ", res->val);
        res = res->next;
    }
    printf("\n");
}