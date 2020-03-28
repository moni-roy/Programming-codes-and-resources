#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[100010],cnt=0,as;
map<ll,ll>mp;

int main(){
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	sort(a,a+n);
	for(ll i=0;i<n;i++){
		if(mp[a[i]]) {
			as=a[i]*m;
			cnt++;
			if(mp[as]){
				mp[as]=0;
			}
		}
	}
	cout<<cnt<<endl;
}
