#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll fun(ll a, ll p, ll m){
	if(p==0) return 1;
	if(p%2==0){
		return ((fun(a,p/2,m)%m)*(fun(a,p/2,m)%m))%m;
	}
	else
	{
		return ((a%m)*(fun(a,p-1,m)%m))%m;
	}
}

int main(){
	ll a,p,m,ans;
	while(cin>>a>>p>>m)
	{
		ans=fun(a,p,m);
		cout<<ans<<endl;
	}
	return 0;
}
