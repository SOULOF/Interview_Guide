#include <iostream>
#include <string>
#include <stack>
#include <cassert>

using namespace std;

template <typename T>

class twostackQueue
{   
    private:
    stack<T> stackPush, stackPop;
    public:

    void add(int newNum)
    {
        stackPush.push(newNum);
    }

    void poll()
    {
        //assert(!(stackPush.empty() && !stackPop.empty()));
        if(stackPop.empty())
        {
            while (!stackPush.empty())
            {
                stackPop.push(stackPush.top());
                stackPush.pop();
            }
        }
        stackPop.pop();
    }

    int peel()
    {
        //assert(!(stackPush.empty() && !stackPop.empty()));
        if(stackPop.empty())
        {
            while (!stackPush.empty())
            {
                stackPop.push(stackPush.top());
                stackPush.pop();
            }
        }
        return stackPop.top();

    }

};

int main()
{   
    int N, newNum;
    twostackQueue<int> s;
    std::cin >> N;
    string operation;
    while(N--)
    {
        cin >> operation;
        if(operation == "add")
        {
            cin >> newNum;
            s.add(newNum);
        }
        else if (operation == "poll")
            s.poll();
        else
        {
            std :: cout << s.peel() << endl;
        }
    }
    return 0;
}