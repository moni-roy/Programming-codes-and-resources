#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

#define LL long long

using namespace std;

int main()
{
	LL fst,snd,a,b,cop;
	while(cin>>a>>b)
	{
		if(a+b==0) break;
		fst=min(a,b);
		snd=max(a,b);
		LL reslt=0,num=fst;
		if(fst==1)
		{
			reslt=3;
			//num=fst;
		}
		for(LL i=fst;i<=snd;i++)
		{
			LL cnt=0;
			cop=i;
			while(cop!=1)
			{
				if(cop%2==1) cop=(3*cop)+1;
				else cop/=2;
				cnt++;
			}
			if(cnt>reslt)
			{
				reslt=cnt;
				num=i;
			}
		}
		printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",fst,snd,num,reslt);
	}
	return 0;
}
