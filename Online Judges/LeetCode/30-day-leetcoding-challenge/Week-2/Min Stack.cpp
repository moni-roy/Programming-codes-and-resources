class MinStack
{
public:
    /** initialize your data structure here. */
    vector<pair<int, int>> minStack;
    int mn = -1, sz = 0;
    MinStack()
    {
        minStack.clear();
        sz = 0;
    }

    void push(int x)
    {
        if (sz)
        {
            mn = min(mn, x);
        }
        else
        {
            mn = x;
        }
        minStack.push_back({x, mn});
        sz++;
    }

    void pop()
    {
        minStack.pop_back();
        sz--;
        if (sz)
            mn = minStack.back().second;
    }

    int top()
    {
        return minStack.back().first;
    }

    int getMin()
    {
        return minStack.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */