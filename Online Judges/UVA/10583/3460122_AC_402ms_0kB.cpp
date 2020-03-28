#include <bits/stdc++.h>
using namespace std;

int cs=0,n,m,x,y,ans,par[55000];
int FND(int i)
{
    if(par[i]==i) return i;
    return par[i]=FND(par[i]);
}
void make_set(int i,int j)
{
    int u=FND(i);
    int v=FND(j);
    if(u!=v)
    {
        par[v]=u;
        ans--;
    }
}
int main()
{
    while(cin>>n>>m)
    {
        if(m==0&&n==0) break;
        for(int i=1;i<=n;i++) par[i]=i;
        ans=n;
        for(int i=0;i<m;i++)
        {
            cin>>x>>y;
            make_set(x,y);
        }
        cout<<"Case "<<++cs<<": "<<ans<<endl;
    }
}
