#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long unsigned llu;
typedef double dl;

#define sci(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scs(s) scanf("%s",s)
#define vi vector<int>
#define vl vector<ll>
#define zero(a) memset(a,0,sizeof a)
#define minus(a) memset(a,-1,sizeof a)
#define mii map<int,int>
#define msi map<string,int>
#define mci map<char,int>
#define sti set<int>
#define sts set<string>
#define nl puts("")
#define pri(a) printf("%d",a)
#define prl(a) printf("%lld",a)
#define pru(a) printf("%llud",a)
#define CS(a) printf("Case %d: ",++a)
vl v,prm;
ll vis[3000000],n,t,sq,cnt,ans;

void fun()
{
	prm.push_back(2);
	for(ll i=3;i*i<3000000;i+=2)
	{
		if(vis[i]==0)
		{
			prm.push_back(i);
			for(ll j=i*i;j<3000000;j+=i+i)
			{
				vis[j]=1;
			}
		}
	}
	v.push_back(0);
	v.push_back(0);
	v.push_back(1);
	for(ll i=3;i<2900000;i++)
	{
		sq=i;cnt=0;ans=0;
		for(ll j=0;prm[j]*prm[j]<=sq;j++)
		{
			cnt=0;
			while(sq%prm[j]==0)
			{
				cnt++;
				sq/=prm[j];
			}
			ans+=cnt;
		}
		if(sq>1) ans++;
		v.push_back(ans);
	}
	for(ll i=1;i<(ll)v.size();i++)
	{
		v[i]+=v[i-1];
	}
}

int main()
{
	fun();
    scl(t);
    while(t--)
    {
		//vector<ll>::iterator an;
		scl(n);
		ll an=upper_bound(v.begin(),v.end(),n)-v.begin();
		prl(an),nl;
    }
    return 0;
}
