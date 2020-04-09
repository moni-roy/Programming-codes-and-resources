class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        stack<char> first, second;

        for (auto c : S)
        {
            if (c == '#')
            {
                if (!first.empty())
                    first.pop();
            }
            else
                first.push(c);
        }
        for (auto c : T)
        {
            if (c == '#')
            {
                if (!second.empty())
                    second.pop();
            }
            else
                second.push(c);
        }
        if (first.size() != second.size())
            return false;
        while (!first.empty())
        {
            if (first.top() != second.top())
                return false;
            first.pop();
            second.pop();
        }
        return true;
    }
};