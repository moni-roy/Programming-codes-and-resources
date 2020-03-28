#include <bits/stdc++.h>
using namespace std;
long long n,sq;
int main(){
	while(cin>>n&&n){
		sq=sqrt((double)n);
		if(sq*sq==n) cout<<"yes\n";
		else cout<<"no\n";
	}
	return 0;
}
