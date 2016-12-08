#include <bits/stdc++.h>
using namespace std;
int ts,cs=0,a,b,c;
int main(){
	cin>>ts;
	while(ts--){
		cin>>a>>b>>c;
		if(a<=20&&b<=20&&c<=20) cout<<"Case "<<++cs<<": good"<<endl;
		else cout<<"Case "<<++cs<<": bad"<<endl;
	}
	return 0;
}
