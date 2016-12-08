#include<bits/stdc++.h>
#define ld double
#define ll long long int
#define scldd(x,y) scanf("%lf%lf",&x,&y)
#define scld(x) scanf("%lf",&x)
#define scll(x,y) scanf("%lld%lld",&x,&y)
#define scl(x) scanf("%lld",&x)

using namespace std;

int main()
{
	ll a,b,ar;
	while(scll(a,b)==2)
	{
		map<ll,ll>mk;
			for(ll i=1;i<=b;i++) 
			{
				scl(ar);
				mk[ar]++;
			}
			ll flag=0;
			//sort(mk.begin(),mk.end());
			for(ll i=1;i<=a;i++)
			{
				if(mk[i]==0)
				{
					flag=1;
					cout<<i<<" ";
				}
			}
			if(flag==0) cout<<"*";
			puts("");
	}
	return 0;
}
