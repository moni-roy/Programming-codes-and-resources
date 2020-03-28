#include <bits/stdc++.h>
using namespace std;
#define MX 1005
bool vs[MX],flg[MX][MX];
int SCC[MX],dp[MX],Group;
vector<int> g[MX],rg[MX],stk;
void dfs(int u) {
    vs[u]=1;
    for(int i=0; i<(int)g[u].size(); i++) {
        if(!vs[ g[u][i] ]) dfs(g[u][i]);
    }
    stk.push_back(u);
}
void DFS(int u) {
    vs[u]=0;
    dp[Group]++;
    for(int i=0; i<(int)rg[u].size(); i++) {
        if(vs[ rg[u][i] ]) DFS(rg[u][i]);
    }
    SCC[u]=Group;
}
void FindSCC(int n) {
    for(int i=1; i<=n; i++) {
        if(!vs[i]) dfs(i);
    }
    for(int i=stk.size()-1; i>=0 ; i--) {
        if(vs[stk[i]]) {
            Group++;
            DFS(stk[i]);
        }
    }
}
int Dfs(int u) {
    vs[u]=1;
    int ret = dp[u];
    for(int i=0; i<(int)g[u].size(); i++) {
        if(!vs[g[u][i]]) ret+=Dfs(g[u][i]);
    }
    return ret;
}
void BuildDAG(int n) {
    for(int i=0; i<=n; i++) g[i].clear();
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(SCC[i]==SCC[j]) continue;
            if(flg[i][j]) {
                g[SCC[i]].push_back(SCC[j]);
            }
        }
    }
    int Ans = 0;
    for(int i=1; i<=Group; i++) {
        int ret = Dfs(i);
        if(ret == n) {
            Ans+=dp[i];
        }
    }
    cout<<Ans<<endl;
}
void INIT(int n) {
    for(int i=0; i<=n; i++) {
        g[i].clear();
        rg[i].clear();
        vs[i]=0;
        dp[i]=0;
    }
    memset(flg,0,sizeof flg);
    stk.clear();
    Group=0;
}
int main() {
    int ts,n;
    cin>>ts;
    while(ts--) {
        cin>>n;
        INIT(n);
        for(int i=1; i<=n; i++) {
            int k;
            cin>>k;
            for(int j=0; j<k; j++) {
                int a;
                cin>>a;
                g[a].push_back(i);
                rg[i].push_back(a);
                flg[a][i]=1;
            }
        }
        FindSCC(n);
        BuildDAG(n);
    }
    return 0;
}
