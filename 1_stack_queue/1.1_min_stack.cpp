#include <iostream>
#include <stack>
#include <string>
#include <climits>
#include <cassert>
 
using namespace std;
 
template <typename T>
class minStack{
    private:
    stack<T> data_stack;
    stack<T> min_stack;

    public:
    minStack()
    {
        min_stack.push(INT_MAX);
    }
    void push(T newNum)
    {   
        data_stack.push(newNum);
        min_stack.push(min(newNum, min_stack.top()));   
    }

    void pop()
    {   
        assert(!data_stack.empty());
        data_stack.pop();
        min_stack.pop();
    }
    int getMin()
    {   
        assert(!data_stack.empty());
        return min_stack.top();
    }
};
 
int main()
{   
/*
    input:
        6
        push 3
        push 2
        push 1
        getMin
        pop
        getMin
    output:
    1
    2
*/
    minStack<int> s;
    int n;
    cin >> n;
    string operation;
    int item;
    while(n--){
        cin >> operation;
        if(operation == "push"){
            cin >> item;
            s.push(item);
        }else if(operation == "getMin"){
            cout << s.getMin() << endl;
        }else if(operation == "pop"){
            s.pop();
        }
    }
    return 0;
}