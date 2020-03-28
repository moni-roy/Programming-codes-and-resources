#include <bits/stdc++.h>
using namespace std;
long long n,k,an;
int main(){
	cin>>n>>k;
	if((n+1)/2>=k){
		//odd
		an=1+(k-1)*2;
	}
	else{
		k=k-((n+1)/2);
		//cout<<k<<endl;
		//even
		an=2+(k-1)*2;
	}
	cout<<an<<endl;
}
