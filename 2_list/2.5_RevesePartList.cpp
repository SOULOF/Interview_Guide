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


list_node * reverse_list(list_node * head, int L, int R)
{
        list_node* dumy = new list_node();
        dumy->next = head;
        list_node* pre = dumy;
        for (int i = 1; i < L; i++)
            pre = pre->next;
        list_node *cur = pre->next, *last = pre->next;
        list_node *pre0 = pre;
        list_node* tmp;
        for (int i = L; i <= R; i++)
            {
                tmp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = tmp;
            }
        pre0->next = pre;
        last->next = cur;
        return dumy->next;
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
    int L, R;
    list_node * head = input_list();
    scanf("%d%d", &L, &R);
    list_node * new_head = reverse_list(head, L, R);
    print_list(new_head);
    return 0;
}