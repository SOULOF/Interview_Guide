# include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int v): val(v), next(NULL){}
};

ListNode* insert(ListNode* head, int val)
{
    if (head == nullptr)
    {
        head = new ListNode(val);
        head->next = head;
    }
    else
    {
        ListNode* p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = new ListNode(val);
        p->next->next = head;
    }
    return head;
}

void display(ListNode *head)
{
    if (head == nullptr)
        cout << endl;
    else
    {
        ListNode *p = head;
        while (p->next != head)
        {
            cout << p->val << "->";
            p = p->next;
        }
        cout << p->val << endl;
    }
}

ListNode* josephCircle(ListNode *head, int m)
{
    if (!head || !head->next || m < 1)
        return head;
    ListNode* last = head;
    while (last->next != head)
        last = last->next;
    int count = 0;
    while (head != last)
    {
        if (++count == m)
        {
            last->next = head->next;
            count = 0;
        }
        else
        {
            last = last->next;
        }
        head = last->next;
    }
    return head;
}


int main()
{   

    return 0;
}