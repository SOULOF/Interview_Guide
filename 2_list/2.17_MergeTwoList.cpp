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


list_node * merge_list(list_node * l1, list_node * l2)
{
  if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val < l2->val)
        {
            l1->next = merge_list(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = merge_list(l1, l2->next);
            return l2;
} 
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
    list_node * head1 = input_list();
    list_node * head2 = input_list();
    list_node * new_head = merge_list(head1, head2);
    print_list(new_head);
    return 0;
}