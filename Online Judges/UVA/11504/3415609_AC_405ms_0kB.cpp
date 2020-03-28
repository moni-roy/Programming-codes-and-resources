#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>v,grp[100010];
int n,m,x,y,t,vs[100010];
void bfs(int st)
{
    queue<int>q;
    q.push(st);
    vs[st]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<(int)grp[u].size(); i++)
        {
            int v=grp[u][i];
            if(vs[v]==0)
            {
                vs[v]=1;
                q.push(v);
            }
        }
    }
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0; i<m; i++)
        {
            cin>>x>>y;
            grp[x].push_back(y);
        }
        memset(vs,0,sizeof vs);
        for(int i=1; i<=n; i++)
        {
            if(vs[i]==0)
            {
                bfs(i);
                v.push_back(i);
            }
        }
        ll ans=0;
        memset(vs,0,sizeof vs);
        for(int i=v.size()-1; i>=0; i--)
        {
            if(vs[v[i]]==0)
            {
                bfs(v[i]);
                ans++;
            }
        }
        cout<<ans<<endl;
        v.clear();
        for(int i=0;i<=n;i++)
            grp[i].clear();
    }
}
