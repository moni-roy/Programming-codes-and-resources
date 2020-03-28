#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 1;i<=k;i++){
		if(i%n ==0 && i%m==0) cout<<"FizzBuzz"<<endl;
		else if(i%n==0) cout<<"Fizz"<<endl;
		else if(i%m==0) cout<<"Buzz"<<endl;
		else cout<<i<<endl;
	}
	return 0;
}
