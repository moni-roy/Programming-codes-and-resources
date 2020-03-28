#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int lmt = 1e6;
const int MX = lmt + 5;

template<class T> inline string toString(T t)
{
    stringstream ss;
    ss << t;
    return ss.str();
}

struct node
{
    int cnt;
    node *nd[10];
    node()
    {
        cnt = 0;
        for (int i = 0; i < 10; i++) nd[i] = NULL;
    }
};

void ins(string s, node *rt)
{
    for (int i = 0; i < s.size(); i++)
    {
        int t = s[i] - '0';
        if (rt->nd[t] == NULL)
        {
            rt->nd[t] = new node();
            rt->nd[t]->cnt = 0;
        }
        rt->nd[t]->cnt++;
        rt = rt->nd[t];
    }
}
ll findMin(string s, node *rt)
{
    ll ret = 0;
    int f = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int t = s[i] - '0';
        for (int j = 0; j < 10; j++)
        {
            int p = (j - t + 10) % 10;
            if (rt->nd[p] != NULL)
            {
                if (p == t && f == 0)
                {
                    if (rt->nd[p]->cnt > 1)
                    {
                        ret = ret * 10ll + (p + t) % 10;
                        rt = rt->nd[p];
                        break;
                    }
                }
                else
                {
                    if (rt->nd[p]->cnt)
                    {
                        ret = ret * 10ll + (p + t) % 10;
                        rt = rt->nd[p];
                        f = 1;
                        break;
                    }
                }
            }
        }
    }
    return ret;
}
ll findMax(string s, node *rt)
{
    ll ret = 0;
    int f = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int t = s[i] - '0';
        for (int j = 9; j >= 0; j--)
        {
            int p = (j - t + 10) % 10;
            if (rt->nd[p] != NULL)
            {
                if (p == t && f == 0)
                {
                    if (rt->nd[p]->cnt > 1)
                    {
                        ret = ret * 10ll + (p + t) % 10;
                        rt = rt->nd[p];
                        break;
                    }
                }
                else
                {
                    if (rt->nd[p]->cnt)
                    {
                        ret = ret * 10ll + (p + t) % 10;
                        rt = rt->nd[p];
                        f = 1;
                        break;
                    }
                }
            }
        }
    }
    return ret;
}
string s[MX];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    node *rt = new node();
    rt->cnt = 0;
    ll n, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        string ss = toString(a);
        s[i] = ss;
        reverse(s[i].begin(), s[i].end());
        while (s[i].size() < 19) s[i] += "0";
        reverse(s[i].begin(), s[i].end());
        ins(s[i], rt);
    }
    long long AnsX = 2e18, Ansy = 0, ret;
    for (int i = 0; i < n; ++i)
    {
        ret = findMin(s[i], rt);
        AnsX = min(AnsX, ret);
        ret = findMax(s[i], rt);
        Ansy = max(Ansy, ret);
    }
    cout << AnsX << " " << Ansy << endl;
    return 0;
}
