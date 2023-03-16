#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int tops = -1;
    int max_size = 5;

public:
    int *stk = (int *)calloc(max_size, sizeof(int));

    void push(int x)
    {

        if (tops + 1 == max_size)
        {
            // cout<<"new memory allocated"<<endl;
            stk = (int *)realloc(stk, max_size + 5);
            if (stk == nullptr)
            {
                // cout<<"new memory allocation failed...exiting the program"<<endl;
                exit(1);
            }
            max_size += 5;
        }
        stk[++tops] = x;
    }

    void pop()
    {
        if (tops == -1)
        {
            // cout<<"under flow"<<endl;
            return;
        }

        tops--;
    }

    void peek()
    {
        if (tops == -1)
        {
            // cout<<"Empty Stack"<<endl;
            return;
        }

        cout << stk[tops] << endl;
    }

    int top()
    {
        if (tops == -1)
        {
            // cout<<"Empty Stack"<<endl;
            return -1;
        }
        return stk[tops];
    }

    int size()
    {
        return (tops + 1);
    }

    bool Empty()
    {
        if (tops == -1)
        {
            return true;
        }
        return false;
    }
};

class DinnerPlates
{
public:
    int size;
    int tops = 0;
    int rightmost = 0;
    int j = 0;

    DinnerPlates(int capacity)
    {
        this->size = capacity;
    }

    Stack a[20000];

    void push(int val)
    {

        while (a[tops].size() == size)
        {
            ++tops;
            rightmost++;
        }
        // if(tops==-1)tops=0;
        a[tops].push(val);
    }

    int pop()
    {
        if (tops == -1)
        {
            return -1;
        }
        // if(j==0){
        //     return -1;
        // }

        tops = rightmost;

        while (a[tops].size() == 0)
        {
            tops--;

            if (tops < 0)
            {
                break;
            }
        }

        if (tops < 0)
        {
            tops = -1;
            return -1;
        }

        // rightmost = tops;

        int temp = a[tops].top();
        a[tops].pop();

        return temp;
    }

    int popAtStack(int index)
    {
        if (a[index].size() == 0)
        {
            return -1;
        }

        int temp = a[index].top();
        a[index].pop();
        tops = index;
        return temp;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */

int main()
{
    DinnerPlates D = DinnerPlates(2); // Initialize with capacity = 2
    D.push(1);
    D.push(2);
    D.push(3);
    D.push(4);
    D.push(5); // The stacks are now:  2  4
               // 1  3  5
               // ﹈ ﹈ ﹈

    cout << D.popAtStack(0) << endl; // Returns 2.  The stacks are now:     4
                                     // 1  3  5
                                     // ﹈ ﹈ ﹈

    D.push(20); // The stacks are now: 20  4
                // 1  3  5
                // ﹈ ﹈ ﹈

    D.push(21); // The stacks are now: 20  4 21
                // 1  3  5
                // ﹈ ﹈ ﹈

    cout << D.popAtStack(0) << endl; // Returns 20.  The stacks are now:     4 21
                                     // 1  3  5
                                     // ﹈ ﹈ ﹈

    cout << D.popAtStack(2) << endl; // Returns 21.  The stacks are now:     4
                                     // 1  3  5
                                     // ﹈ ﹈ ﹈

    cout << D.pop() << endl; // Returns 5.  The stacks are now:      4
                             // 1  3
                             // ﹈ ﹈

    cout << D.pop() << endl; // Returns 4.  The stacks are now:   1  3
                             // ﹈ ﹈

    cout << D.pop() << endl; // Returns 3.  The stacks are now:   1
                             // ﹈

    cout << D.pop() << endl; // Returns 1.  There are no stacks.

    cout << D.pop() << endl; // Returns -1.  There are still no stacks.

    return 0;
}
