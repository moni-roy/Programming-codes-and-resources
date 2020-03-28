#include <bits/stdc++.h>
using namespace std;

map<string, string>par;
map<string, int>sz;
map<string, int>mp;
int t,k,n;
string s,ss;

string FIND(string x)
{
    if(par[x]==x) return x;
    return par[x]=FIND(par[x]);
}
int make_set(string x,string y)
{
    string u=FIND(x);
    string v=FIND(y);
    if(u!=v)
    {
        par[v]=u;
        return sz[u]=sz[u]+sz[v];
    }
    return sz[u];
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        k=0;
        for(int i=0;i<n;i++)
        {
            cin>>s>>ss;
            if(par[s]=="") par[s]=s;
            if(par[ss]=="") par[ss]=ss;
            if(sz[s]==0) sz[s]=1;
            if(sz[ss]==0) sz[ss]=1;
            cout<<make_set(s,ss)<<endl;
        }
        sz.clear();
        par.clear();
    }
}
