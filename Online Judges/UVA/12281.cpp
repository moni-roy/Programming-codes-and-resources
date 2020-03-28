#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fact[50];
ll ts,cs=0,nm,a[50],ans;
void factorial(){
	fact[0]=1;
	fact[1]=2;
	for(ll i=2;i<=50;i++){
		fact[i]=fact[i-1]+fact[i-2];
	}
}
ll mini(ll n){
	ll cnt=0;
	for(ll i=50-1;i>=0;i--){
		if(n>=fact[i]){
			cnt++;
			//if(cnt>1) cnt1++;
			n-=fact[i];
			//cout<<n<<" "<<cnt<<endl;
		}
	}
	return cnt;
}
			
int main(){
	factorial();
	cin>>ts;
	while(ts--){
		cin>>nm;
		for(ll i=0;i<nm;i++){
			cin>>a[i];
		}
		ans=1;
		for(ll i=0;i<nm;i++){
			ans*=mini(a[i]);
		}
		cout<<"Case "<<++cs<<": "<<ans<<endl;
	}
	return 0;
}
