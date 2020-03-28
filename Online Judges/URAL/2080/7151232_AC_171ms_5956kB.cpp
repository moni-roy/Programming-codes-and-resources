#include <bits/stdc++.h>
using namespace std;
long long tr[100111],m,n,a[100100],vs[100100];
#define MX 100110
void update(int p,int vl){
	while(p<=MX){
		tr[p]+=vl;
		p+=(p&-p);
	}
}
int query(int p){
	int ret = 0;
	while(p>0){
		ret+=tr[p];
		p-=(p&-p);
	}
	return ret;
}
vector<int>vv[100010],v;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		vv[a[i]].push_back(i);
		if(!vs[a[i]]){
			v.push_back(a[i]);
			vs[a[i]]=1;
			update(i,1);
		}
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
	for(int i=1;i<=n;i++){
		reverse(vv[i].begin(),vv[i].end());
	}
	for(int i=1;i<=m;i++){
		update(i,-1);
		int Ans = 0;
		int sz = vv[a[i]].size(); 
		if(sz==1) Ans = n-1;
		else {
			vv[a[i]].pop_back();
			int p = vv[a[i]].size();
			int t = vv[a[i]][p-1];
			update(t,1);
			Ans = query(t-1);
		}
		cout<<Ans<<endl;
	}
	cout<<endl;
	return 0;
}
