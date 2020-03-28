#include <bits/stdc++.h>
using namespace std;
int n,m,pb,mx;
int main(){
	cin>>n>>m;
	mx=max(n,m);
	pb=6-mx+1;
	if(pb==6){
		cout<<"1/1"<<endl;
	}
	else{
		int gd=__gcd(6,pb);
		//cout<<pb<<" "<<gd<<endl;
		cout<<pb/gd<<"/"<<(6/gd)<<endl;
	}
}
