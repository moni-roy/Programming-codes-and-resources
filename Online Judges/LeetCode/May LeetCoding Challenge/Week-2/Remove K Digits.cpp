class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string ret = "";
        if (num.size() == k)
            return "0";
        int i = 0;
        stack<char> st;
        while (k && i < num.size())
        {
            char ch = num[i++];
            if (st.empty())
            {
                st.push(ch);
            }
            else
            {
                char t = st.top();
                while (!st.empty() && st.top() > ch && k)
                {
                    k--;
                    st.pop();
                }
                st.push(ch);
            }
        }
        if (k == 0)
        {
            while (!st.empty())
            {
                ret += st.top();
                st.pop();
            }
            reverse(ret.begin(), ret.end());
            for (; i < num.size(); i++)
                ret += num[i];
        }
        else
        {
            while (k--)
            {
                st.pop();
            }

            while (!st.empty())
            {
                ret += st.top();
                st.pop();
            }
            reverse(ret.begin(), ret.end());
        }
        i = 0;
        while (ret[i] == '0')
            i++;
        ret = ret.substr(i);
        return ret.size() ? ret : "0";
    }
};