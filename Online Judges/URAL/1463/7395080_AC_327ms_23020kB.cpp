#include <bits/stdc++.h>
using namespace std;
const int MX = 1000007;
typedef long long int ll;

vector<pair<int,ll> > g[MX];
int pr[MX],a[MX],id;
bool vis[MX];
ll vs[MX];

void bfs(int s)
{
    queue<pair<int,int> >q;
    q.push({s,-1});
    vs[s] = a[s];
    id = s;
    while(!q.empty())
    {
        int x = q.front().first;
        int p = q.front().second;
        q.pop();
        vis[x]=1;
        if(vs[x]>vs[id])
        {
            id = x;
        }
        for(int i=0; i<(int)g[x].size(); i++)
        {
            int y = g[x][i].first;
            ll z = g[x][i].second;
            if(p==y) continue;
            q.push({y,x});
            vs[y]=vs[x]+z+a[y];
        }
    }
}
void bfs2(int s,int e)
{
    queue<int>q;
    q.push(e);
    memset(vs,0,sizeof vs);
    vs[e] = 1;
    pr[e] = -1;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        if(x==s) break;
        for(int i=0; i<(int)g[x].size(); i++)
        {
            int y = g[x][i].first;
            if(vs[y]==1) continue;
            vs[y]=1;
            pr[y]=x;
            q.push(y);
        }
    }
    vector<int>Ans;
    while(s!=-1)
    {
        Ans.push_back(s);
        s = pr[s];
    }
//    Ans.push_back(s);
    cout<<Ans.size()<<endl;
    for(int i=0; i<(int)Ans.size(); i++)
    {
        if(i!=0) cout<<" "<<Ans[i];
        else cout<<Ans[i];
    }
    cout<<endl;
}

int main()
{
    ll n,m,x,y,z;
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=0; i<m; i++)
    {
        cin>>x>>y>>z;
        g[x].push_back({y,z});
        g[y].push_back({x,z});
    }
    ll Ans = -1;
    int AnsX=0,AnsY=0,st=0;

    for(int i=1; i<=n; i++)
    {
        if(vis[i]==0)
        {
            bfs(i);
            st = id;
            bfs(st);
            if(vs[id]>Ans)
            {
                Ans = vs[id];
                AnsX=st;
                AnsY=id;
            }
        }
    }
    cout<<Ans<<endl;
    bfs2(AnsX,AnsY);
    return 0;
}
