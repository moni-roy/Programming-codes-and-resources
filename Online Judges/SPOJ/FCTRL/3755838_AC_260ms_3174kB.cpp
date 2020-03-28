#include <bits/stdc++.h>
using namespace std;
long long  ts,n,cnt;
int main(){
	cin>>ts;
	while(ts--){
		cin>>n;
		cnt=0;
		while(n>=5){
			cnt+=n/5;
			n/=5;
		}
		cout<<cnt<<endl;
	}
}
