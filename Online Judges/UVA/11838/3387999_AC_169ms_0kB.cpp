#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t,cs=0,n,u,m,v,c,p,vs[2200],cnt;
vector<int>adj[2200];

void fun(int s)
{
    if(vs[s]) return ;
    vs[s]=1;
    cnt++;
    //cout<<"BBBB "<<s<<endl;
    for(int i=0; i<adj[s].size(); i++)
    {
        int x=adj[s][i];
        //      cout<<"MMM <"<<x<<endl;

        fun(x);
    }
    return ;
}
int main()
{
    while(cin>>n>>m&&n&&m)
    {
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&u,&v,&p);
            if(p==2)
            {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            else
            {
                adj[v].push_back(u);
            }
        }
        int flg=0;
        for(int i=1; i<=n; i++)
        {
            memset(vs,0,sizeof vs);
            cnt=0;
            fun(i);
            if(cnt<n)
            {
                flg=1;
                break;
            }

        }
        if(flg) cout<<0<<endl;
        else cout<<1<<endl;
        for(int i=0; i<=n; i++)
            adj[i].clear();
    }
    return 0;
}
