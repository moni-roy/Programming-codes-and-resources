#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int vs[110000],t,n,m,u,v,cnt;
vector<int>adj[110000];

void fun(int s)
{
    queue<int>q;
    vs[s]=1;
    q.push(s);
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(int i=0;i<(int)adj[x].size();i++)
        {
            int y=adj[x][i];
            if(vs[y]==0)
            {
                vs[y]=1;
                q.push(y);
            }
        }
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(vs,0,sizeof vs);
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
        }
        cnt=0;
        vector<int>vv;
        for(int i=1;i<=n;i++)
        {
            if(vs[i]==0)
            {
                fun(i);
                vv.push_back(i);
            }
        }
        memset(vs,0,sizeof vs);
        for(int i=vv.size()-1;i>=0;i--)
        {
            if(vs[vv[i]]==0)
            {
                fun(vv[i]);
                cnt++;
            }
        }
        cout<<cnt<<endl;
        for(int i=0;i<=n;i++)
            adj[i].clear();
    }
    return 0;
}
