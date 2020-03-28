#include <bits/stdc++.h>
using namespace std;

int main(){
	int a[100],sv[100],n;
	a[1]=1;
	a[2]=1;
	for(int i=3;i<44;i++){
		a[i]=a[i-2]+a[i-1];
	}
	sv[1]=1;
	for(int i=2;i<44;i++){
		sv[i]=sv[i-1]+a[i];
	}
	while(cin>>n){
		cout<<sv[n]<<endl;
	}
}
