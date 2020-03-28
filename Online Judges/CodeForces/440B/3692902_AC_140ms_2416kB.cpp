#include <bits/stdc++.h>
using namespace std;
long long int n,a[50005],av,tl=0,an=0,df;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		tl+=a[i];
	}
	av=tl/n;
	for(int i=0;i<n;i++){
		df=abs(av-a[i]);
		if(df==0) continue;
		if(av<a[i]){
			an+=df;
			a[i+1]+=df;
		}
		else {
			an+=df;
			a[i+1]-=df;
		}
	}
	cout<<an<<endl;
	//main();
}
