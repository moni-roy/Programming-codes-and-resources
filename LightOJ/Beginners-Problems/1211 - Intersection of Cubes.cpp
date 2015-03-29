#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
	ll t,cs=0,n,x1,x2,z1,z2,y1,y2,mxx,mxy,mxz,mnx,mny,mnz;
	cin>>t;
	while(t--)
	{
		cin>>n;
		mnx=mny=mnz=0;
		mxx=mxy=mxz=10000000;
		while(n--)
		{
			cin>>x1>>y1>>z1>>x2>>y2>>z2;
			mnx=max(mnx,x1);
			mny=max(mny,y1);
			mnz=max(mnz,z1);
			mxx=min(mxx,x2);
			mxy=min(mxy,y2);
			mxz=min(mxz,z2);
		}
		cout<<"Case "<<++cs<<": ";
		ll volume=(mxx-mnx)*(mxy-mny)*(mxz-mnz);
		if(volume<0)
		{
			cout<<0<<endl;
		}
		else cout<<volume<<endl;
	}
	return 0;
}
