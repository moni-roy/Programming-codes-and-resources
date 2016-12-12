bool vs[MX],flg[MX][MX];
int SCC[MX],dp[MX],Group=0;
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
}
