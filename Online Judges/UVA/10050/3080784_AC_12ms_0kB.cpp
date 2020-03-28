#include <bits/stdc++.h>
using namespace std;
int a[100000],ts,d,p,cnt,x;
int main(){
	cin>>ts;
	while(ts--){
		cin>>d;
		cin>>p;
		memset(a,0,sizeof a);
		while(p--){
			cin>>x;
			for(int i=0;i<=d;i+=x){
				a[i]=1;
			}
		}
		cnt=0;
		for(int i=1;i<=d;i++){
			if(a[i]==1 && i%7!=6 && i%7!=0) cnt++;
		}
		cout<<cnt<<endl;
	}
}
