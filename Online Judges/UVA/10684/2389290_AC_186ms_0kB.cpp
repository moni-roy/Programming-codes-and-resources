#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
	ll n,sum,ar;
	while(cin>>n&&n)
	{
		sum=-999999999;
		ll mx=-999999999;
		while(n--)
		{
			cin>>ar;
			sum=max(ar,sum+ar);
			mx=max(mx,sum);
		}
		if(mx<=0)
		{
			cout<<"Losing streak."<<endl;
		}
		else cout<<"The maximum winning streak is "<<mx<<"."<<endl;
	}
	return 0;
}
