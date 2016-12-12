#define md 1000000007ll
vector<p> g[100010]; 
bool vs[100010];
ll prim(ll x){
	priority_queue<p,vector<p>,greater<p> >pq;
	memset(vs,false,sizeof vs);
	ll ret=1;
	pq.push({1,x});
	while(!pq.empty()){
		ll u=pq.top().first;
		ll v=pq.top().second;
		pq.pop();
		if(vs[v]) continue;
		u%=md;
		ret*=u;
		ret%=md;
		vs[v]=true;
		for(int i=0;i<(int)g[v].size();i++){
			u=g[v][i].second;
			if(!vs[u]) pq.push(g[v][i]);
		}
	}
	return ret%md;
}
