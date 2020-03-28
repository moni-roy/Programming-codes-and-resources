#include <bits/stdc++.h>
using namespace std;
int t,m,n,l,ans,cnt,x,y,vs[10001];
vector<int>sv[10001];
void fun(int s)
{
    if(vs[s]==1) return;
    cnt++;
    vs[s]=1;
    for(int i=0; i<sv[s].size(); i++)
    {
        fun(sv[s][i]);
    }
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>l;
        for(int i=0; i<m; i++)
        {
            cin>>x>>y;
           // sv[y].push_back(x);
            sv[x].push_back(y);
        }
        memset(vs,0,sizeof vs);
        ans=0;
        for(int i=0; i<l; i++)
        {
            cin>>x;
            cnt=0;
            fun(x);
            ans+=cnt;
        }
        cout<<ans<<endl;
        for(int i=0;i<=n;i++) sv[i].clear();
    }
}
