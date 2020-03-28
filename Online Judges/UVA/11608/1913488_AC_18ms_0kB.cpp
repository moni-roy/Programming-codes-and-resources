#include<iostream>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

#include<cmath>
#include<cstdio>
#include<cstring>

#define MOD 1000003
#define LL long long
#define LLU long long unsigned
#define PB push_back
#define SCL(x) scanf("%d",&x)
#define SCLL(x) scanf("%lld",&x)

using namespace std;

int main()
{
	LL num,mnt[15],prb[15],cas=0;
	while(SCLL(num)&&num>=0)
	{
		for(int i=0;i<12;i++) SCLL(mnt[i]);
		for(int i=0;i<12;i++) SCLL(prb[i]);
		LL sum=num;
		cout<<"Case "<<++cas<<":\n";
		for(int i=0;i<12;i++)
		{
			if(prb[i]<=sum)
			{
				cout<<"No problem! :D\n";
				sum-=prb[i];
			}
			else cout<<"No problem. :(\n";
			sum+=mnt[i];
		}
	}
	return 0;
}
