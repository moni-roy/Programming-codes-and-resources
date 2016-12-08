#include <bits/stdc++.h>
using namespace std;

int n,x,Ans,m,a[1009];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int cs=0;
	while(cin>>n && n){
		for(int i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		cout<<"Case "<<++cs<<":"<<endl;
		cin>>m;
		while(m--){
			cin>>x;
			int d=999999999;
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					if(abs(a[i]+a[j]-x)<d){
						Ans=a[i]+a[j];
						d=abs(a[i]+a[j]-x);
					}
				}
			}
			
			cout<<"Closest sum to "<<x<<" is "<<Ans<<"."<<endl;
		}
	}
	return 0;
}
				
