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
	ll a,max,sum;
	string num;
	while(getline(cin,num))
	{
		stringstream ss(num);
		ll aa;
		sum=0;
		max=0;
		while(ss>>aa)
		{
			a=aa;
			if(sum>0) sum+=a;
			else sum=a;
			if(sum>=max)
			{
				max=sum;
			}
		}
		cout<<max<<endl;
	}
	return 0;
}
