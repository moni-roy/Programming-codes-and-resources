#include <bits/stdc++.h>
using namespace std;

int m,n,t,par[10001],x,y,mx,sz[10010];
int FIND(int p)
{
    if(par[p]==p) return p;
    return par[p]=FIND(par[p]);
}

void set_make(int i,int j)
{
    int u=FIND(i);
    int v=FIND(j);
    if(v!=u)
    {
        sz[u]=sz[u]+sz[v];
        par[v]=u;
    }
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        for(int i=1; i<=m; i++)
        {
            par[i]=i;
            sz[i]=1;
        }
        for(int i=0; i<n; i++)
        {
            cin>>x>>y;
            set_make(x,y);
        }
        mx=0;
        for(int i=1; i<=m; i++)
        {
            mx=max(mx,sz[i]);
        }
        cout<<mx<<endl;
    }
}
