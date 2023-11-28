#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} Node;

struct ListNode *deleteDuplicates(struct ListNode *head)
{
    if (!head || !head->next)
        return head;
    Node *curr = head;
    while (curr->next)
    {
        while (curr->next && curr->val == curr->next->val)
        {
            Node *tmp = curr->next;
            curr->next = curr->next->next;
            free(tmp);
        }
        if (curr->next)
            curr = curr->next;
    }
    return head;
}

Node *new_list(int arr[], int len)
{
    int i = 1;
    Node *head = calloc(1, sizeof(Node));
    Node *curr = head;
    curr->val = arr[0];
    while(i < len)
    {
        curr->next = calloc(1,sizeof(Node));
        curr = curr->next;
        curr->val = arr[i];
        i++;
    }
    return head;
}

int main(void)
{
    int arr[] = {1,2,2,3,4, 4};
    int len = sizeof(arr)/sizeof(int);
    Node *head = new_list(arr, len);
    head = deleteDuplicates(head);
    int i = 0;
    while(head)
    {
        printf("%d, ", head->val);
        head = head->next;
        i++;
    }
    printf("\n");
}
