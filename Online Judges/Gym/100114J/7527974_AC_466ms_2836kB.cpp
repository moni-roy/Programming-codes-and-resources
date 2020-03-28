#include <bits/stdc++.h>
using namespace std;
#define MX 10004
int vs[MX],pr[MX],lw[MX],ds[MX],qs[MX],ls[MX];
int sz = 0,cnt=0,cmp=0,kd=0;
vector<int>g[MX],gr[MX];
int st[MX];
void dfs(int u,int pp=-1) {
    vs[u]=1;
    ds[u]=lw[u]=++cnt;
    st[sz++]=u;
    bool fl=0;
    for(int i=0; i<(int)g[u].size(); i++) {
        int v=g[u][i];
        if(pp==v && fl==0) {
            fl=1;
            continue;
        }
        if(!vs[v]) {
            dfs(v,u);
            lw[u]=min(lw[u],lw[v]);
        } else if(ls[v]==0) {
            lw[u]=min(lw[u],ds[v]);
        }
    }
    if(lw[u]==ds[u]) {
        cmp++;
        qs[cmp]=u;
        int v;
        do {
            v = st[--sz];
            ls[v]=cmp;
        } while(v!=u);
    }
}
void bridge(int n) {
    memset(vs,0,sizeof vs);
    for(int i=1; i<=n; i++) {
        if(!vs[i]) {
            dfs(i);
        }
    }
}
int sv[MX];
int DFS(int u,int id,int d) {
    sv[u]=d;
    int ret = u;
    for(int i=0; i<(int)gr[u].size(); i++) {
        int v = gr[u][i];
        if(v!=id) {
            int ret1 = DFS(v,u,d+1);
            if(sv[ret]<sv[ret1]) ret = ret1;
        }
    }
    return ret;
}
int main() {
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    int n,m,a,b;
    cin>>n>>m;
    for(int i=0; i<m; i++) {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bridge(n);
    for(int i=1; i<=n; i++) {
        for(int j=0; j<(int)g[i].size(); j++) {
            int v = g[i][j];
            if(ls[i]==ls[v]) continue;
            gr[ls[i]].push_back(ls[v]);
        }
    }
    int x = DFS(1,-1,0);
    int y = DFS(x,-1,0);
    cout<<qs[x]<<" "<<qs[y]<<endl;
    return 0;
}
/*
5 6
1 2
2 3
3 1
4 3
4 5
5 4



7 7
1 2
2 3
2 4
2 6
3 4
4 5
6 7
*/
