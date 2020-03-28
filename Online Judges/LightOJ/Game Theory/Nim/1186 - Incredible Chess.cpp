#include <bits/stdc++.h>
using namespace std;

int main()
{
	int ts,cs=0,Ans,a[10001],b,n;
	cin>>ts;
	while(ts--){
		cin>>n;
		Ans = 0;
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++){
			cin>>b;
			Ans^=abs(b-a[i]-1);
		}
		cout<<"Case "<<++cs<<": ";
		if(Ans) cout<<"white wins"<<endl;
		else cout<<"black wins"<<endl;
	}
	return 0;
}
