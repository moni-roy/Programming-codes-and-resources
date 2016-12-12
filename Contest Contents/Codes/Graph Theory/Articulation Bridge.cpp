vector<pair<int,int> > Ans;
int n,ds[100010],lw[100010],pr[100010],vs[100100];
vector<int> adj[100010];
int cnt=0;
void dfs(int u){
    vs[u]=1;
    ds[u]=lw[u]=++cnt;
    for(int i=0;i<(int)adj[u].size();i++){
        int v=adj[u][i];
        if(!vs[v]){
            pr[v]=u;
            dfs(v);
            lw[u]=min(lw[u],lw[v]);
            if(lw[v]>ds[u]){
                Ans.push_back(make_pair(min(u,v),max(u,v)));
            }
        }
        else if(v!=pr[u]){
            lw[u]=min(lw[u],ds[v]);
        }
    }
}
// Multiple edges from a to b are not allowed.
// (they could be detected as a bridge).
// If you need to handle this, just count
// how many edges there are from a to b.
void bridge(){
    minus(pr);
    zero(vs);
    zero(lw);
    zero(ds);  
    for(int i=0;i<n;i++){
        if(!vs[i]){
            cnt=0;
            dfs(i);
        }
    }
}
