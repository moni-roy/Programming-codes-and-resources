#include <bits/stdc++.h>
using namespace std;
long long n,ts;
int main(){
	cin>>ts;
	while(ts--){
		cin>>n;
		if(n<4){
			cout<<n<<endl;
			}
		else{
			if(n%2){
				cout<<4<<endl;
			}
			else cout<<3<<endl;
		}
	}
}
