#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *head = NULL;

struct ListNode *insertionSortList(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode headAddress;
    headAddress.next = head;
    struct ListNode *curr = head->next;
    head->next = NULL;
    while (curr != NULL)
    {
        struct ListNode *prev = &headAddress;
        struct ListNode *next = curr->next;
        while (prev->next != NULL && prev->next->val < curr->val)
        {
            prev = prev->next;
        }
        curr->next = prev->next;
        prev->next = curr;
        curr = next;
    }
    return headAddress.next;
}

int main()
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = 5;
    head->next = NULL;

    struct ListNode *a = (struct ListNode *)malloc(sizeof(struct ListNode));
    a->val = 1;
    a->next = NULL;
    head->next = a;

    struct ListNode *b = (struct ListNode *)malloc(sizeof(struct ListNode));
    b->val = 3;
    b->next = NULL;
    a->next = b;

    struct ListNode *c = (struct ListNode *)malloc(sizeof(struct ListNode));
    c->val = 2;
    c->next = NULL;
    b->next = c;

    struct ListNode *d = (struct ListNode *)malloc(sizeof(struct ListNode));
    d->val = 4;
    d->next = NULL;
    c->next = d;

    head = insertionSortList(head);
    struct ListNode *t = head;
    while (t != NULL)
    {
        printf("%d ", t->val);
        t = t->next;
    }
    return 0;
}