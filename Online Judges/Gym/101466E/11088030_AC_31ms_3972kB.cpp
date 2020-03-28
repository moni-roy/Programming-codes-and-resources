#include <bits/stdc++.h>
using namespace std;

vector<int>zf(string s)
{
    int n = s.size();
    vector<int>z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    string s, t;
    getline(cin, s);
    getline(cin, t);
    s = t + "#" + s;
    //    cout << s << endl;
    vector<int>z = zf(s);
    cin >> k;
    vector<int>v;
    for (int i = t.size() + 1; i < z.size(); i++)
    {
        if (z[i]) v.push_back(z[i]);
    }
    sort(v.begin(), v.end());
    int Ans = 0;
    for (int i = v.size() - 1; i >= 0 && k; i--, k--)
    {
        Ans = v[i];
    }
    if (k == 0 && Ans)
    {
        for (int i = 0; i < Ans; i++) cout << t[i];
        cout << endl;
    }
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}
