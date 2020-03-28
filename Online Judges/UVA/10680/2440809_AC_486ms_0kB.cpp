#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1000007
vector<ll>prm;
ll ok[mx];
void sieve()
{
	for(ll i=2;i<mx;i+=2) ok[i]=i;
	prm.push_back(2);
	for(ll i=3;i<mx;i+=2)
	{
		if(!ok[i])
		{
			for(ll j=i*3;j<mx;j+=i*2)
			{
				ok[j]=j;
			}
			prm.push_back(i);
		}
	}
	swap(prm[1],prm[2]);
}
int main()
{
	sieve();
	ll n;
	while(cin>>n&&n)
	{
		ll ans=1;
		ll cn2=0,cn5=0;
		for(ll i=2;i<=n;i*=2) cn2++;
		for(ll i=5;i<=n;i*=5) cn5++;
		for(ll i=0;i<cn2-cn5;i++)
		{
			ans=(ans*2)%10;
		}
		ll k=2;
		while(prm[k]<=n)
		{
			for(ll i=prm[k];i<=n;i*=prm[k])
			{
				ans=(ans*prm[k])%10;
			}
			k++;
		}
		cout<<ans<<endl;
	}
}
