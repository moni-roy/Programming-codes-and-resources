#include <bits/stdc++.h>
using namespace std;
long long int n,k,a[10010],sm=0;
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	long long int mx=0;
	sm=0;
	for(int i=0;i<k&&i<n;i++){
		sm+=(-1*a[i]);
		mx=max(mx,sm);
	}
	cout<<mx<<endl;
	//main();
}
