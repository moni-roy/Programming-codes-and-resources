#include<bits/stdc++.h>
#define ld double
#define ll long long int
#define scldd(x,y) scanf("%lf%lf",&x,&y)
#define scld(x) scanf("%lf",&x)
#define scll(x,y) scanf("%lld%lld",&x,&y)
#define scl(x) scanf("%lld",&x)
#define sci(x) scanf("%d",&x)
#define scic(x,y) scanf(" %c %d",&x,&y)
#define scal(x,y,c,s) scanf("%lld%lld %c %s",&x,&y,&c,s)
#define sclll(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define scs(x,y) scanf("%s %s",x,y)

using namespace std;

int main()
{
	int tst,ans,black,ar[10],i;
	char que[]={'A','B','C','D','E'};
	while(sci(tst)==1&&tst)
	{
		while(tst--)
		{
			black=0;
		for(i=0;i<5;i++)
		{
			sci(ar[i]);
			if(ar[i]<=127)
			{
				black++;
				ans=i;
			}
		}
		if(black==1) printf("%c\n",que[ans]);
		else puts("*");
	}
}
	return 0;
}
	
