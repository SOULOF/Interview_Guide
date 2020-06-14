# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

list_node * input_list()
{
    int val, n;
    scanf("%d", &n);
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
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


list_node * remove_value(list_node * head, int num)
{
    list_node* cur = head, *pre;
    while (cur)
    {
        if (cur->val == num)
        {
            pre->next = cur->next;
        }
        else
        {
            pre = cur;
        }
        cur = cur->next;
    }
    return head;
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
    int num;
    scanf("%d", &num);
    list_node * new_head = remove_value(head, num);
    print_list(new_head);
    return 0;
}