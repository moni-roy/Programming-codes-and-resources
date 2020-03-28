#include <bits/stdc++.h>
using namespace std;
const long long MD = 100000007;
long long sv[1010][2005];
int vis[1010][2005];
int vs[2005], n, m, ts, T;
long long go(vector<int> &a, int p, int xr)
{
    if (p >= n)
    {
        return (xr > 1000) || (vs[xr] == 0);
    }
    long long &ret = sv[p][xr];
    if (vis[p][xr] == T) return ret;
    vis[p][xr] = T;
    ret = 0;
    ret = go(a, p + 1, xr);
    ret += go(a, p + 1, xr ^ a[p]);
    ret %= MD;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int cs = 0;
    cin >> ts;
    while (ts--)
    {
        T++;
        cin >> n >> m;
        vector<int>a(n), b(m);
        for (auto &i : a)
        {
            cin >> i;
        }
        memset(vs, 0, sizeof vs);
        for (auto &i : b)
        {
            cin >> i;
            vs[i] = 1;
        }
//        memset(sv, -1, sizeof sv);
        long long Ans = go(a, 0, 0);
        cout << "Case " << ++cs << ": " << Ans << endl;
    }
    return 0;
}
