# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};


list_node * input_list(void)
{
    int n, val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &val);
        if (i == 1) {
            cur_pnode->val = val;
            cur_pnode->next = NULL;
        }
        else {
            list_node * new_pnode = new list_node();
            new_pnode->val = val;
            new_pnode->next = NULL;
            cur_pnode->next = new_pnode;
            cur_pnode = new_pnode;
        }
    }
    return phead;
}


list_node * relocate(list_node * head)
{
    if (head == NULL || head->next == NULL) return head;
    list_node* mid = head, *right = head->next, *res = head;
    while (right->next && right->next->next)
    {
        mid = mid->next;
        right = right->next->next;
    }
    right = mid->next;
    mid->next = NULL;
    list_node* tmp = new list_node();
    while (head->next)
    {
        tmp = right->next;
        right->next = head->next;
        head->next = right;
        head = right->next;
        right = tmp;
    }
    head->next = right;
    return res;
}


void print_list(list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    puts("");
}


int main ()
{
    list_node * head = input_list();
    list_node * new_head = relocate(head);
    print_list(new_head);
    return 0;
}