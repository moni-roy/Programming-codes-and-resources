struct edge{
    int u,v,w;
    bool operator<(const edge &p) const{
        return w<p.w;
    }
};
int pr[MAXN];
vector<edge>e;
int FIND(int r){return (pr[r]==r)?r:FIND(pr[r]);}
int MST(int n){
	sort(e.begin(),e.end());
    for(int i=1;i<=n;i++) pr[i]=i;
    int cnt=0,s=0;
    for(int i=0;i<(int)e.size();i++){
        int u=FIND(e[i].u);
        int v=FIND(e[i].v);
        if(u!=v){
            pr[u]=v;
            cnt++;
            s+=e[i].w;
            if(cnt==n-1) break; //it can not be a loop
        }
    }
    return s;
}
