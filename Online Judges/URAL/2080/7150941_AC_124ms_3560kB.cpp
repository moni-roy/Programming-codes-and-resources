#include <bits/stdc++.h>
using namespace std;

int tr[400010],m,n,a[100100],Ans[100010],vs[100100],ps[100010];
/*
void update(int p,int vl){
	while(p<=m){
		tr[p]+=vl;
		p+=(p&-p);
	}
}
int query(int s,int p){
	int ret = 0;
	while(p>=s){
		ret+=tr[p];
		p-=(p&-p);
	}
	return ret;
}
*/
void update(int p,int s,int t,int i,int v){
	if(s==t){
		tr[p]=v;
		return;
	}
	int md = (s+t)>>1;
	int l = 2*md;
	int r = l+1;
	if(i<=md) update(l,s,md,i,v);
	else update(r,md+1,t,i,v);
	tr[p]=tr[l]+tr[r];
}
int query(int p,int s,int t,int l,int r){
	if(l>r) return 0;
	if(s==l && r==t){
		return tr[p];
	}
	int md = (s+t)>>1;
	int lg = 2*md;
	int rg = lg+1;
	if(r<=md) return query(lg,s,md,l,r);
	else if(l>md) return query(rg,md+1,t,l,r);
	else return query(lg,s,md,l,md)+query(rg,md+1,t,md+1,r);
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>a[i];
	vector<int>v;
	for(int i=1;i<=m;i++){
		Ans[i]=-1;
		if(!ps[a[i]]){
			v.push_back(a[i]);
			vs[a[i]]=1;
		}
		else{
			update(1,1,m,ps[a[i]],0);
		}
		update(1,1,m,i,1);
		Ans[ps[a[i]]]=query(1,1,m,ps[a[i]]+1,i-1);
		ps[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(vs[i]==0) v.push_back(i);
	}
	int f=0;
	for(int i=0;i<(int)v.size();i++){
		if(f) cout<<" ";
		cout<<v[i];
		f=1;
	}
	cout<<endl;
	for(int i=1;i<=m;i++){
		if(Ans[i]==-1) cout<<n-1<<endl;
		else cout<<Ans[i]<<endl;
	}
	return 0;
}
