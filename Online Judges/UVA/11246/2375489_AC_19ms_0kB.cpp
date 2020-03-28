#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define zero(a) memset(a,0,sizeof a)
#define minus(a) memset(a,-1,sizeof a)
#define pb(a) push_back(a)
#define gcd(a,b) __gcd(a,b)

ll f(ll n,ll k)
{
	if(n<1) return n;
	return n-n/k+f((n/k)/k,k);
}
int main()
{
	ll n,k,tst;
	cin>>tst;
	while(tst--)
	{
		cin>>n>>k;
		ll ans=f(n,k);
		cout<<ans<<endl;
	}
	return 0;
}
