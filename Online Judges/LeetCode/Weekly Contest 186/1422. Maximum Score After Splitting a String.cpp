class Solution
{
public:
    int maxScore(string s)
    {
        int mx = 0, z, o;
        int l = s.size();
        for (int i = 1; i < s.size(); i++)
        {
            z = o = 0;
            for (int j = 0; j < i; j++)
            {
                if (s[j] == '0')
                    z++;
            }
            for (int j = i; j < s.size(); j++)
                if (s[j] == '1')
                    o++;
            mx = max(mx, z + o);
        }
        return mx;
    }
};