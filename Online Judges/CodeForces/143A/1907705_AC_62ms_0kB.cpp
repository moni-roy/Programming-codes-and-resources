#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>

#include<cmath>
#include<cstdio>

#define LL long long int
#define LLU long long unsigned
#define SCLI2(x,y) scanf("%lld%lld",&x,&y)

using namespace std;

int main()
{
	LL r1,r2,c1,c2,d1,d2,p,q,x,y;
	SCLI2(r1,r2);
	SCLI2(c1,c2);
	SCLI2(d1,d2);
	LL flag=0;
	for(x=1;x<10;x++)
	{
		q=(r2-c1+x);
		y=r1-x;
		p=c1-x;
		if(x+q==d1&&y+p==d2&&x!=y&&x!=p&&y!=p&&q!=p&&q!=x&&q!=y&&0<y&&y<10&&0<p&&p<10&&0<q&&q<10)
		{
			flag=1;
			goto mk;
		}
	}
	mk:
	if(flag)
	{
		cout<<x<<' '<<y<<endl;
		cout<<p<<' '<<q<<endl;
	}
	else puts("-1");
	//main();
	return 0;
}
