#include <bits/stdc++.h>
using namespace std;
int a[1001],ts,cnt,n,cs=0;
int main(){
	cin>>ts;
	while(ts--){
		cin>>n;
		cnt=0;
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n-1;i++){
			int id=-1;
			int mx=a[i];
			for(int j=i+1;j<n;j++){
				if(a[j]<mx){
					id=j;
					mx=a[j];
				}
			}
			if(id!=-1){
				swap(a[i],a[id]);
				cnt++;
			}
		}
		cout<<"Case "<<++cs<<": "<<cnt<<endl;
	}
}
