#include <bits/stdc++.h>
using namespace std;
typedef long long unsigned ll;
ll n,m,q,sm,k;
string sss,ss[10000],qs;
map<string,ll>mp;

struct str
{
    string s;
    int x;

} st[100001];
ll fun(string mk)
{
    int ln=mk.length();
    ll dec=0;
    ll k=0;
    for(int i=ln-1; i>=0; i--)
    {
        dec+=(ll)((ll)(mk[i]-'0')*(ll)pow(double(2),k));
        k++;
    }
    return dec;
}

int main()
{
    while(cin>>n>>m)
    {
        mp.clear();
        sm=0;
        for(int i=0; i<m; i++)
        {
            cin>>st[i].s>>st[i].x;
            sm+=st[i].x;
        }
        for(int i=0; i<sm; i++)
        {
            cin>>ss[i];
        }
        k=0;
        for(int i=0; i<m; i++)
        {
            sss="";
            for(int j=0; j<st[i].x; j++)
            {
                sss+=ss[k];
                k++;
            }
            mp[st[i].s]=fun(sss);
        }
        cin>>q;
        while(q--)
        {
            cin>>qs;
            if(mp.count(qs)) cout<<qs<<"="<<mp[qs]<<endl;
            else
                cout<<qs<<"=\n";
        }
    }
    return 0;
}
