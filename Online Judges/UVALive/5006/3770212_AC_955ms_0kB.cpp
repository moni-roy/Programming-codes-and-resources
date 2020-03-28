#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll ts,m,n,a[1000010],b[1000010],mx,an;
string F(ll x){
	string rt="";
	while(x>0){
		rt+=(x%2+'0');
		x/=2;
	}
	return rt;
}
ll fun(ll x,ll y){
	ll cnt=0;
	string dx=F(x);
	string dy=F(y);
	ll xl=dx.size();
	ll yl=dy.size();
	ll ln=max(xl,yl);
	for(ll i=0;i<ln;i++){
		if(i>=xl) dx+='0';
		if(i>=yl) dy+='0';
		//if(i>=xl||i>=yl) cnt++;
		if(dx[i]!=dy[i]) cnt++;
	}
	return cnt;
}

int main(){
	cin>>ts;
	while(ts--){
		cin>>m>>n;
		for(ll i=0;i<m;i++) cin>>a[i];
		for(ll i=0;i<n;i++) cin>>b[i];
		sort(a,a+m);
		for(ll i=0;i<n;i++){
			mx=999999999;
			for(ll j=0;j<m;j++){
				ll f=fun(b[i],a[j]);
				if(f<mx){
					mx=f;
					an=a[j];
				}
			}
			cout<<an<<endl;
		}
	}
}
