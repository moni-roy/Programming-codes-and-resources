#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,d,r,a[1001],b[1001],ans;
	while(cin>>n>>d>>r){
		if(n+d+r==0) break;
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++) cin>>b[i];
		sort(a,a+n);
		sort(b,b+n);
		ans=0;
		for(int i=0,j=n-1;i<n;i++,j--)
		{
			if((a[i]+b[j])>d) ans+=(a[i]+b[j]-d)*r;
		}
		cout<<ans<<endl;
	}
	return 0;
}
