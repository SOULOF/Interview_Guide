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

list_node * selection_sort(list_node * head)
{
    //////在下面完成代码
   list_node* cur = head;
    vector<int> v;
    while (cur) {
        v.push_back(cur->val);
        cur = cur->next;
    }
    sort(v.begin(), v.end());
   
    vector<int>::iterator iter = v.begin();
    cur = head;
    while (cur) {
        cur->val = *(iter++);
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
    list_node * new_head = selection_sort(head);
    print_list(new_head);
    return 0;
}