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


list_node* check(list_node * head)
{
    stack<int> st;
    list_node* cur = head;
    while(cur)
    {
        st.push(cur->val);
        cur = cur->next;
    }
    cur = head;
    while(cur && !st.empty())
    {
        if (cur->val != st.top())
        {    
            cout << "false" << endl;
            return head;
        }
            
        st.pop();
        cur = cur->next;
    }
    cout << "true" << endl;
    return head;
}


int main ()
{
    int L, R;
    list_node * head = input_list();
    check(head);
}