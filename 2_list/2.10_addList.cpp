# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
    list_node(int x):val(x), next(NULL) {}
};

list_node * input_list(int n)
{
    int val;
    list_node * phead = new list_node(-1);
    list_node * cur_pnode = phead;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &val);
        if (i == 1) {
            cur_pnode->val = val;
            cur_pnode->next = NULL;
        }
        else {
            list_node * new_pnode = new list_node(-1);
            new_pnode->val = val;
            new_pnode->next = NULL;
            cur_pnode->next = new_pnode;
            cur_pnode = new_pnode;
        }
    }
    return phead;
}
list_node* reverse(list_node* head)
    {
        list_node* pre = NULL, *cur = head;
        while (cur)
        {
            list_node* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

list_node * add_list(list_node * head1, list_node * head2)
{        
        head1 = reverse(head1);
        head2 = reverse(head2);
        list_node* res = new list_node(0);
        int v1, v2, sum = 0, carry = 0;
        list_node* pre = res;
        while(head1 != NULL || head2 != NULL)
        {
            v1 = head1 == NULL? 0 : head1 -> val;
            v2 = head2 == NULL? 0 : head2 -> val;
            sum = v1 +v2 + carry;
            carry = sum / 10;
            sum %= 10;
            res -> next = new list_node(sum);
            res = res -> next;
            if(head1 != NULL) head1 = head1 -> next;
            if(head2 != NULL) head2 = head2 -> next;
        }
        if(carry == 1) res -> next = new list_node(carry);
        return reverse(pre->next);

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
    int n, m;
    scanf("%d%d", &n, &m);
    list_node * head1 = input_list(n), * head2 = input_list(m);
    list_node * new_head = add_list(head1, head2);
    print_list(new_head);
    return 0;
}