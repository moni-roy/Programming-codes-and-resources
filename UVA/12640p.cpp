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
	ll ans,max,sum;
	string num;
	while(getline(cin,num))
	{
		stringstream ss(num);
		vector<ll>mk;
		ll aa;
		while(ss>>aa)
		{
			mk.push_back(aa);
		}
			sum=0;
			ans=0;
			max=0;
		for(ll i=0;i<mk.size();i++)
		{
			if(sum>0) sum+=mk[i];
			else sum=mk[i];
			if(sum>=max)
			{
				max=sum;
				ans=sum;
			}
		}
		cout<<max<<endl;
	}
	return 0;
}

