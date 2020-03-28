#include<bits/stdc++.h>
#define ld double
#define ll long long int
#define scldd(x,y) scanf("%lf%lf",&x,&y)
#define scld(x) scanf("%lf",&x)
using namespace std;
void combination(ld x, ld y)
{
	ld ans=1;
	for(ll i=x;i>x-y;i--)
	{
		ans*=i;
	}
	for(ll i=1;i<=y;i++)
	{
		ans/=i;
	}
	printf("%.0lf things taken %.0lf at a time is %.0lf exactly.\n",x,y,ans);
	
}
int main()
{
	ld a,b;
	while(scldd(a,b)==2)
	{
		if(!(a+b)) break;
		combination(a,b);
	}
	return 0;
}
