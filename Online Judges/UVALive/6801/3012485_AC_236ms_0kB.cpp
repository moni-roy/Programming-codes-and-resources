#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define md 1000000007
#define minus(a) memset(a,-1,sizeof a)

ll ts,n,k,one,zero,cs=0,a[1010],str[1011][1011];
bool vis[1010][1010];

ll func(ll o,ll z, ll s){
	if(s==k){
		if(z==n) return 1;
		return 0;
	}
	ll ret=0;
	if(vis[z][s]==true) return str[z][s];
	if(o){
		ret=ret+(o*func(o-1,z+1,s+1))%md;
	}
	if(z) 
	{
		ret=ret+(z*func(o+1,z-1,s+1))%md;
	}
	vis[z][s]=true;
	return (str[z][s]=ret%md);
}
int main(){
	cin>>ts;
	while(ts--){
		cin>>n>>k;
		one=0;
		for(ll i=0;i<n;i++) {
			cin>>a[i];
			if(a[i]) one++;
		}
		zero=n-one;
		//minus(str);
		memset(vis, 0,sizeof vis);
		ll ans=func(one,zero,0);
		cout<<"Case #"<<++cs<<": "<<ans<<endl;
	}
	return 0;
}
