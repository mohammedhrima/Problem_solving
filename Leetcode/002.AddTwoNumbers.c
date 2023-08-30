
struct ListNode
{
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;
Node *new_node(int value)
{
    Node *new = calloc(1, sizeof(Node));
    new->val = value;
    return new;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    if (!l1 && !l2)
        return new_node(0);
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    Node *curr = new_node(0);
    Node *ret = curr;
    while (l1 || l2)
    {
        curr->val += (l1 && l2) ? l1->val + l2->val : l1 ? l1->val
                                                  : l2   ? l2->val
                                                         : curr->val;
        if ((l1 && l1->next) || (l2 && l2->next) || curr->val >= 10)
            curr->next = new_node(0);
        if (curr->val >= 10)
        {
            curr->next->val = curr->val / 10;
            curr->val %= 10;
        }
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
        curr = curr->next;
    }
    return ret;
}