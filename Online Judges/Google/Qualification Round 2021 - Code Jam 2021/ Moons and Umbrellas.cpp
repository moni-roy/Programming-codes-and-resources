#include <bits/stdc++.h>

using namespace std;
int x, y, sv[1001][3], vs[1001][3];
int dp(int p, string s, int f)
{
    if (p == s.size())
        return 0;
    if (vs[p][f])
        return sv[p][f];
    vs[p][f] = 1;
    int &res = sv[p][f];
    res = 0;
    if (s[p] == 'C' && f == 0)
    {
        res = y + dp(p + 1, s, 1);
    }
    else if (s[p] == 'J' && f)
    {
        res = x + dp(p + 1, s, 0);
    }
    else if (s[p] == '?')
    {
        if (f == 1)
        {
            res = min(dp(p + 1, s, 1), x + dp(p + 1, s, 0));
        }
        else
            res = min(y + dp(p + 1, s, 1), dp(p + 1, s, 0));
    }
    else
    {
        res = dp(p + 1, s, f);
    }
    return res;
}
int main()
{
    int ts, cs = 0;
    cin >> ts;
    while (ts--)
    {
        int ans = 0;
        memset(vs, 0, sizeof vs);
        string s;
        cin >> x >> y >> s;
        if (s[0] == '?')
        {
            ans = min(dp(1, s, 1), dp(1, s, 0));
        }
        else
        {
            if (s[0] == 'C')
            {
                ans = dp(1, s, 1);
            }
            else
                ans = dp(1, s, 0);
        }
        cout << "Case #" << ++cs << ": " << ans << endl;
    }
    return 0;
}