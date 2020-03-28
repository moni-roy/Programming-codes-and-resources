#include <bits/stdc++.h>
using namespace std;
template<class T> inline T BMOD(T p, T e, T m)
{
    T ret = 1;
    while (e > 0)
    {
        if (e & 1) ret = (ret * p) % m;
        e >>= 1;
        p *= p;
        p %= m;
    }
    return ret % m;
}
const int MX = 2e6 + 4;
const long long MD = 1e9 + 7;
vector<int>prm = {2, 3, 5, 7, 11, 13};
int tim = 1;
vector<int>g[MX];
int st[MX], en[MX], vs[10];
int tr[MX][10];
void dfs(int u, int p = -1)
{
    st[u] = tim++;
    for (auto v : g[u])
    {
        if (v == p) continue;
        dfs(v, u);
    }
    en[u] = tim++;
}

void up(int p)
{
    while (p < MX)
    {
        for (int j = 0; j < 6; j++)
        {
            tr[p][j] += vs[j];
        }
        p += (p & -p);
    }
}
void qry(int p)
{
    while (p > 0)
    {
        for (int j = 0; j < 6; j++)
        {
            vs[j] += tr[p][j];
        }
        p -= (p & -p);
    }
}
void qry2(int p)
{
    while (p > 0)
    {
        for (int j = 0; j < 6; j++)
        {
            vs[j] -= tr[p][j];
        }
        p -= (p & -p);
    }
}

void fuck(int k)
{
    memset(vs, 0, sizeof vs);
//    cout << "OK" << endl;
    qry(en[k]);
    qry2(st[k] - 1);
    long long div = 1;
    long long nm = 1;
    for (int i = 0; i < 6; i++)
    {
        div *= (long long)(vs[i] + 1ll);
        if (div >= MD) div %= MD;
        nm *= BMOD((long long)(prm[i]), (long long)(vs[i]), MD);
        if (nm >= MD) nm %= MD;
    }
    cout << nm << " " << div << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int n, u, v, q, k, t;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        memset(vs, 0, sizeof vs);
        for (int j = 0; j < 6; j++)
        {
            if (t == 1) break;
            while (t % prm[j] == 0)
            {
                t /= prm[j];
                vs[j]++;
            }
        }
        up(st[i]);
    }
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        if (s == "RAND")
        {
            cin >> k;
            fuck(k);
        }
        else
        {
            cin >> k >> t;
            memset(vs, 0, sizeof vs);
            for (int j = 0; j < 6; j++)
            {
                if (t == 1) break;
                while (t % prm[j] == 0)
                {
                    t /= prm[j];
                    vs[j]++;
                }
            }
            up(st[k]);
        }
    }
    return 0;
}
