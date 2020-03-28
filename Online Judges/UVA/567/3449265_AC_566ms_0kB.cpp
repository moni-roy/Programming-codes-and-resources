#include <bits/stdc++.h>
using namespace std;
vector<int>adj[110];
int st,en,vs[111],x,y,t,cs=0;
int fun(int s)
{
    memset(vs,0,sizeof vs);
    queue<int>q;
    q.push(s);
    vs[s]=1;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            if(!vs[v])
            {
                if(v==en) return vs[u];
                vs[v]=vs[u]+1;
                q.push(v);
            }
        }
    }
    return 0;
}
int main()
{
    while(cin>>x)
    {
        for(int i=0;i<x;i++)
        {
            cin>>y;
            adj[1].push_back(y);
            adj[y].push_back(1);
        }
        for(int i=2; i<20; i++)
        {
            cin>>x;
            for(int j=0; j<x; j++)
            {
                cin>>y;
                adj[i].push_back(y);
                adj[y].push_back(i);
            }
        }
        //if(cs) cout<<endl;
        cin>>t;
        cout<<"Test Set #"<<++cs<<endl;
        while(t--)
        {
            cin>>st>>en;
            int as=fun(st);
            //cout<<st<<" to "<<en<<": "<<as<<endl;
            printf("%2d to %2d: %d\n",st,en,as);
        }
        cout<<endl;
        for(int i=1;i<=100;i++) adj[i].clear();
    }
}
