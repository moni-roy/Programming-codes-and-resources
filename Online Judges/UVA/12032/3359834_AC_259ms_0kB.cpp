#include <bits/stdc++.h>
using namespace std;

int main()
{
	int ts,cs=0,n,a[100010],mx;
	a[0]=0;
	cin>>ts;
	while(ts--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		mx=a[n]-a[n-1];
		for(int i=n-2;i>=0;i--){
			if(mx==(a[i+1]-a[i])) mx++;
			 mx=max(mx,(a[i+1]-a[i]));
		}
		cout<<"Case "<<++cs<<": "<<mx<<endl;
	}
	return 0;
}
