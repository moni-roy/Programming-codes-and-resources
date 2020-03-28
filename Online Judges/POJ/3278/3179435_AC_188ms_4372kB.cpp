#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;
#define ll long long

ll cnt=0,s,dt,vis[200010],i,j,d[200010];

ll bfs(ll x,ll y)
{
    cnt=0;
    memset(vis,0,sizeof vis);
    memset(d,0,sizeof d);
    queue<ll>q;
    q.push(x);
    while(!q.empty())
    {
        ll u=q.front();q.pop();
        vis[u]=1;
        //cout<<d[u]<<endl;
        if(u==y)
        {
            //cout<<d[u]<<endl;
            return d[u];
        }
        if(u-1>=0&&!vis[u-1])
        {
            vis[u-1]=1;
            d[u-1]=d[u]+1;
            q.push(u-1);
        }
        if(u+1<=y&&!vis[u+1])
        {
            vis[u+1]=1;
            d[u+1]=d[u]+1;
            q.push(u+1);
        }
        if(u<=y&&!vis[u*2])
        {
            vis[u*2]=1;
            d[u*2]=d[u]+1;
            q.push(u*2);
        }
    }
}
int main()
{
    cin>>s>>dt;
    cnt=bfs(s,dt);
    cout<<cnt<<endl;
    //cout<<cnt<<endl;
    return 0;
}
