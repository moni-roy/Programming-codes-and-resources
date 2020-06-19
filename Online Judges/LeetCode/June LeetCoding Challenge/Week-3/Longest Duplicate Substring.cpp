class Solution
{
public:
    unsigned long long bs = 29;
    unsigned long long base[100010], hs[100010];
    void pre()
    {
        base[0] = 1;
        for (int i = 1; i < 100001; i++)
        {
            base[i] = base[i - 1] * bs;
        }
    }

    string valid(int m, string s)
    {
        hs[0] = 0;
        for (int i = 0; i < m; i++)
        {
            hs[i + 1] = hs[i] * bs + (s[i] - 'a' + 1);
        }
        map<unsigned long long, bool> mp;
        mp[hs[m]] = 1;
        for (int i = m; i < s.size(); i++)
        {
            hs[i + 1] = hs[i] * bs + (s[i] - 'a' + 1);
            unsigned long long cur = hs[i + 1] - (hs[i - m + 1] * base[m]);
            if (mp.find(cur) != mp.end())
                return s.substr(i - m + 1, m);
            mp[cur] = 1;
        }
        return "";
    }

    string longestDupSubstring(string S)
    {
        pre();
        int l = 1, h = S.size() - 1;
        string Ans = "";
        while (l <= h)
        {
            int m = (l + h) / 2;
            string s = valid(m, S);
            if (s != "")
            {
                Ans = s;
                l = m + 1;
            }
            else
            {
                h = m - 1;
            }
        }
        return Ans;
    }
};