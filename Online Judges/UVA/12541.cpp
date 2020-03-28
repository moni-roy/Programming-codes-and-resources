/*---------------------------------------------------------.
 *                                                          *
 * Team-phoenix of JU                                       *
 *             Powered by RUM@HELP                          *
 * _________________________________________________________*/
#include<bits/stdc++.h>
#define ld double
#define ll long long int
#define llu long long unsigned
#define scldd(x,y) scanf("%lf%lf",&x,&y)
#define scld(x) scanf("%lf",&x)
#define scll(x,y) scanf("%lld%lld",&x,&y)
#define scl(x) scanf("%lld",&x)
#define sci(x) scanf("%d",&x)
#define scic(x,y) scanf(" %c %d",&x,&y)
#define scal(x,y,c,s) scanf("%lld%lld %c %s",&x,&y,&c,s)
#define sclll(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define scss(x,y) scanf("%s %s",x,y)
#define sc(s,d,m,y) scanf(" %s %lld %lld %lld",s,&d,&m,&y)

using namespace std;

int main()
{
	ll tst,d,m,y,total,mn,mx;
	char nm[100],mmm[100],nnn[100];
	scl(tst);
	mn=4343434343;
	mx=0;
	while(tst--)
	{
		sc(nm,d,m,y);
		total=y*365+m*12+d;
		if(mx<total)
		{
			mx=total;
			strcpy(mmm,nm);
		}
		if(mn>total)
		{
			mn=total;
			strcpy(nnn,nm);
		}
	}
	puts(mmm);
	puts(nnn);
	return 0;
}
