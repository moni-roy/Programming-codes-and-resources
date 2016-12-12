int n,m,ts,cs=0,a,b,c,ds[5][5005],vs[5][5005],Ans;
vpii g[5005];
int dijkstraSecond(int x){
    setinf(ds);
    zero(vs);
    priority_queue<piii,vpiii, greater<piii> >pq;
    ds[1][x]=0;
    pq.P(piii(1,pii(0,x)));
    while(!pq.empty()){
        piii p=pq.top();pq.pop();
        int u=p.S.S, t=p.F;
        if(vs[t][u]) continue;
        else vs[t][u]=1;
        //~ if(u==n and t==2) return ds[2][u];
        //~ if(p.S.F>ds[t][u]) continue;
        for(int i=0;i<(int)g[u].size();i++){
            pii V=g[u][i];
            int v=V.F;
            int tl=ds[t][u]+V.S;
            if(tl<ds[1][v]){
                ds[2][v]=ds[1][v];
                pq.P(piii(2,pii(ds[2][v],v)));
                ds[1][v]=tl;
                pq.P(piii(1,pii(ds[1][v],v)));
            }
            else if(tl>ds[1][v] && tl<ds[2][v]){
                ds[2][v]=tl;
                pq.P(piii(2,pii(ds[2][v],v)));
            }
        }
    }
    return ds[2][n];
}
