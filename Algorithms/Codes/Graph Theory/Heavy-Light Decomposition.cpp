#define MX 30009
vi g[MX];
int pr[MX],lv[MX],sz[MX],sc[MX],hd[MX],tr[4*MX],ch[MX],pos[MX],Ans,ps,no,a[MX];
void DFS(int u,int p,int l){
	pr[u]=p;lv[u]=l;sz[u]=1;sc[u]=-1;
	int mx=-1;
	for(int i=0;i<(int)g[u].size();i++){
		int v=g[u][i];
		if(v!=p){
			DFS(v,u,l+1);
			sz[u]+=sz[v];
			if(sz[v]>mx){
				mx=sz[v];
				sc[u]=v;
			}
		}
	}
}
void HLD(int u){
	if(hd[no]==-1){
		hd[no]=u;
	}
	pos[u]=++ps;
	ch[u]=no;
	if(sc[u]!=-1){
		HLD(sc[u]);
		for(int i=0;i<(int)g[u].size();i++){
			int v=g[u][i];
			if(v!=sc[u] && v!=pr[u]){
				no++;
				HLD(v);
			}
		}
	}
	else{
		for(int i=0;i<(int)g[u].size();i++){
			int v=g[u][i];
			if(v!=sc[u] && v!=pr[u]){
				no++;
				HLD(v);
			}
		}
	}
}
void update(int p,int s,int e,int i,int v){
	if(s==i && e==i){
		tr[p]=v;
		return;
	}
	int m=(s+e)/2;
	int l=p*2;
	int r=l+1;
	if(i<=m) update(l,s,m,i,v);
	else update(r,m+1,e,i,v);
	tr[p]=tr[l]+tr[r];
}
int query(int p,int s,int e,int x,int y){
	if(x<=s && e<=y){
		return tr[p];
	}
	int m=(s+e)/2;
	int l=p*2;
	int r=l+1;
	if(y<=m) return query(l,s,m,x,y);
	else if(x>m) return query(r,m+1,e,x,y);
	return query(l,s,m,x,m)+query(r,m+1,e,m+1,y);
}
		
void LCA(int u,int v){
	int uc=ch[u];
	int vc=ch[v];
	if(uc==vc){
		if(lv[u]<lv[v]){
			Ans+=query(1,1,ps,pos[u],pos[v]);
		}
		else{
			Ans+=query(1,1,ps,pos[v],pos[u]);
		}
		return;
	}
	else{
		int uh=hd[uc];
		int vh=hd[vc];
		if(lv[uh]<lv[vh]){
			Ans+=query(1,1,ps,pos[vh],pos[v]);
			v=pr[vh];
		}
		else{
			Ans+=query(1,1,ps,pos[uh],pos[u]);
			u=pr[uh];
		}
		LCA(u,v);
	}
}
int main()
{
	int ts,cs=0,n,u,v,q,c;
	I(ts);
	while(ts--){
		I(n);
		for(int i=1;i<=n;i++) I(a[i]);
		for(int i=1;i<n;i++){
			I2(u,v);
			u++;v++;
			g[u].pb(v);
			g[v].pb(u);
		}
		DFS(1,-1,1);
		memset(hd,-1,sizeof hd);
		ps=0;
		no=0;
		HLD(1);
		memset(tr,0,sizeof tr);
		for(int i=1;i<=n;i++){
			update(1,1,ps,pos[i],a[i]);
		}
		I(q);
		printf("Case %d:\n",++cs);
		while(q--){
			I3(c,u,v);
			u++;
			v++;
			if(c==0){
				Ans=0;
				LCA(u,v);
				PI(Ans);
				nl;
			}
			else{
				update(1,1,ps,pos[u],v-1);
			}
		}
		for(int i=0;i<=n;i++) g[i].clear();
	}
	return 0;
}
