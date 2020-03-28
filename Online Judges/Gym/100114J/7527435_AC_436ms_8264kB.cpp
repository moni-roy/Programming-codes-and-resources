#include <bits/stdc++.h>
using namespace std;
#define f(a,b) for(a=0;a<b;a++)
#define M 100004
#define pb push_back
int n,m;
vector< int >al[M],ql[M];
bool bg[M];
int a[M],b[M];
int vs[M],lw[M],ctm=1;
int fr[M],qs[M];
int ls[M],cmp;
int st[M],sz=0;
void dfs(int u,int id) {
    vs[u]=lw[u]=ctm++;
    st[sz++]=u;
    int i,v;
    f(i,al[u].size()) {
        v=al[u][i];
        if(v==id)continue;
        v=(a[v]==u)?b[v]:a[v];
        if(vs[v]!=0) {
            lw[u]=min(lw[u],vs[v]);
        } else {
            dfs(v,al[u][i]);
            lw[u]=min(lw[u],lw[v]);
        }
    }
    if(lw[u]==vs[u]) {
        cmp++;
        qs[cmp]=u;
        do {
            v=st[--sz];
            ls[v]=cmp;
        } while(v!=u);
        bg[ id ]=1;
    }
}
int ds[M];
int dfs2(int u,int pr,int d) {
    ds[u]=d;
    int v,i;
    int q=u,q1;
    for(i=0;i<ql[u].size();i++) {
        v=ql[u][i];
        if(v==pr)continue;
        q1=dfs2(v,u,d+1);
        if(ds[q1]>ds[q])q=q1;
    }
    return q;
}

int main() {
    int t,i,j,k;
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    memset(ls,-1,sizeof ls);
    cin>>n>>m;
    f(i,m) {
        cin>>j>>k;
        al[j].pb(i);
        al[k].pb(i);
        a[i]=j;
        b[i]=k;
    }
    cmp=0;
    dfs(1,-1);
    for(i=1; i<=n; i++) {
        if(ls[i]==-1)assert(0);
    }
    f(i,m) {
        if(bg[i]) {
            j=ls[a[i]];
            k=ls[b[i]];
            assert(j!=k);
            ql[j].pb(k);
            ql[k].pb(j);
        }
    }
    j=dfs2(1,-1,0);
    k=dfs2(j,-1,0);
    printf("%d %d\n",qs[j],qs[k]);
    return 0;
}
