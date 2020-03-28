#include <bits/stdc++.h>
using namespace std;

int n,m,mx;
string s,ss,sss;
map<string,string>par;
map<string,int>sz;

string FND(string x)
{
    if(par[x]==x) return x;
    return par[x]=FND(par[x]);
}
void make_set(string i,string j)
{
    string u=FND(i);
    string v=FND(j);
    if(v!=u)
    {
        par[v]=u;
        sz[u]=sz[u]+sz[v];
    }
    mx=max(mx,sz[u]);
}
int main()
{
    while(cin>>n>>m)
    {
        if(n==0&&m==0) break;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            par[s]=s;
            sz[s]=1;
        }
        mx=1;
        for(int i=0;i<m;i++)
        {
            cin>>ss>>sss;
            make_set(ss,sss);
        }
        cout<<mx<<endl;
        sz.clear();
        par.clear();
    }
}
