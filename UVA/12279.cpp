#include <bits/stdc++.h>
using namespace std;
int main(){
	int ts=0,n,ans;
	while(cin>>n&&n){
		int ip;
		ans=0;
		while(n--){
			cin>>ip;
			if(ip) ans++;
			else ans--;
		}
		cout<<"Case "<<++ts<<": "<<ans<<endl;
	}
	return 0;
}
