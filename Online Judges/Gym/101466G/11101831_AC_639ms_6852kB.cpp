#include <bits/stdc++.h>
using namespace std;
template<class T> inline long long toLong(T t)
{
    stringstream ss(t);
    long long ret;
    ss >> ret;
    return  ret;
}
//template<class T> inline string toString(T t)
//{
//    stringstream ss;
//    ss << t;
//    return  ss.str();
//}
const int N = 1e6;
const long long MD = 1e9 + 7;
int lp[N + 1];
vector<int> prm;
void sieveLinear()
{
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            prm.push_back(i);
        }
        for (int j = 0; j < (int)prm.size() && prm[j] <= lp[i] && i * prm[j] <= N; ++j)
            lp[i * prm[j]] = prm[j];
    }
}
vector<int> factors(int n)
{
    vector<int>fc;
    while (n > 1)
    {
        int t = lp[n];
        while (n % t == 0)
        {
            n /= t;
            fc.push_back(t);
        }
    }
    return fc;
}
long long sv[1110];

long long go(string &s, int p)
{
    if (s.size() == p) return 1;
    long long &ret = sv[p];
    if (ret != -1) return ret;
    ret = go(s, p + 1) * (s[p] != '0');
    if ((s[p] != '0') && ((p + 1) < s.size()))
    {
        string ss = "";
        ss += s[p];
        ss += s[p + 1];
        int t = atoi(ss.c_str());
        if (t < 27)
        {
            ret += go(s, p + 2);
            ret %= MD;
        }
    }
    return ret % MD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    sieveLinear();
    int n;
    string s;
    map<int, int>Ans;
    while (cin>>n)
    {
        if (Ans.find(n) == Ans.end())
        {
            vector<int> fct = factors(n);
            s = "";
            for (auto x : fct)
            {
                stringstream ss;
                ss << x;
                s += ss.str();
            }
            sort(s.begin(), s.end());
            long long ret = 0;
            do
            {
                memset(sv, -1, sizeof sv);
                ret += go(s, 0);
                ret %= MD;
            }
            while (next_permutation(s.begin(), s.end()));
            Ans[n] = ret;
        }
        cout<<Ans[n]<<endl;
    }
    return 0;
}

