#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

int getAndRemoveLastElement(stack<int> &s)
{
    int result = s.top();
    s.pop();
    if (s.empty())
        return result;
    else
    {
        int last = getAndRemoveLastElement(s);
        s.push(result);
        return last;
    }
}

void reverseStack(stack<int> &s)
{
    if(s.empty()) return;
    int i = getAndRemoveLastElement(s);
    reverseStack(s);
    s.push(i);
}

int main()
{   
    stack<int> s;
    int N, newNum;
    std :: cin >> N;
    while (N --)
    {
        std :: cin >> newNum;
        s.push(newNum);
    }
    // reverseStack(s); 牛客题目有问题
    while(!s.empty())
    {
        std :: cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}