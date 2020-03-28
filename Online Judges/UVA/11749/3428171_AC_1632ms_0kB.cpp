#include <bits/stdc++.h>
using namespace std;

long long int a[1000011],b[1000011],c[1000011],adj[550][550],vs[550],cnt,n,m,ans,mx;

void fun(long long int x)
{
    if(vs[x]==1) return;
    cnt++;
    vs[x]=1;
    for(int i=1;i<=n;i++)
    {
        if(adj[x][i])
        {
            fun(i);
        }
    }
    return ;
}
int main()
{
    while(cin>>n>>m&&n&&m)
    {
        mx=-99999999999;
        for(int i=0;i<m;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
            mx=max(mx,c[i]);
        }
        memset(adj,0,sizeof adj);
        for(int i=0;i<m;i++)
        {
            if(c[i]==mx)
            {
                adj[a[i]][b[i]]=1;
                adj[b[i]][a[i]]=1;
            }
        }
        ans=-99999999999;
        memset(vs,0,sizeof vs);
        for(int i=1;i<=n;i++)
        {
            if(vs[i]==0)
            {
                cnt=0;
                fun(i);
                ans=max(ans,cnt);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
