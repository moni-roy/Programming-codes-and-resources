class Solution
{
public:
    bool checkValidString(string s)
    {
        int found = 0, start = 0;
        for (auto c : s)
        {
            start += (c == '(') ? 1 : -1;
            found += (c != ')') ? 1 : -1;
            if (found < 0)
                break;
            start = (start > 0) ? start : 0;
        }
        return (start == 0);
    }
};