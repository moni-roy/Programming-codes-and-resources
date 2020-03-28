#include <bits/stdc++.h>
using namespace std;
long long t,a,b;
int main(){
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(b%a){
			cout<<-1<<endl;
		}
		else{
			cout<<a<<" "<<b<<endl;
		}
	}
}
