/*
Ans[i] true for I is a Point. 
*/
int n,ds[MX],lw[MX],pr[MX],vs[MX],Ans[MX];
vector<int> adj[MX];
int cnt=0;
void dfs(int u){
    vs[u]=1;
    ds[u]=lw[u]=++cnt;
    int cn=0;
    for(int i=0;i<(int)adj[u].size();i++){
        int v=adj[u][i];
        if(!vs[v]){
            pr[v]=u;
            cn++;
            dfs(v);
            lw[u]=min(lw[u],lw[v]);
            if(pr[u]==-1 && cn>1) Ans[u]=1; // for root check
           
            if(lw[v]>=ds[u] && pr[u]!=-1){
                Ans[u]=1;
            }
        }
        else if(v!=pr[u]){
            lw[u]=min(lw[u],ds[v]);
        }
    }
}
void ArticulationPoint(){
    minus(pr);
    zero(vs);
    zero(lw);
    zero(ds);
    zero(Ans);
    for(int i=1;i<=n;i++){
        if(!vs[i]){
            cnt=0;
            dfs(i);
        }
    }
}
