#include <bits/stdc++.h>
using namespace std;
int n,p,vs[222],x,y;
vector<int>adj[222];
int FUN(int st)
{
    memset(vs,0,sizeof vs);
    queue<int>Q;
    Q.push(st);
    vs[st]=1;
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        for(int i=0;i<(int)adj[u].size();i++)
        {
            int v=adj[u][i];
            if(!vs[v])
            {
                if(vs[u]==1) vs[v]=2;
                else vs[v]=1;
                Q.push(v);
            }
            if(vs[u]==vs[v]) return 0;
        }
    }
    return 1;
}
int main()
{
    while(cin>>n&&n)
    {
        cin>>p;
        for(int i=0; i<p; i++)
        {
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int ans=FUN(x);
        if(ans!=1) cout<<"NOT BICOLORABLE."<<endl;
        else puts("BICOLORABLE.");

        for(int i=0;i<=n;i++) adj[i].clear();
    }
}
