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

using namespace std;
int save[400];
char str[13010];
int tst,dam,k,m;
char ch;
ld ans;
int main()
{
	
	sci(tst);
	while(tst--)
	{
		memset(save,0,sizeof(save));
		sci(k);
		for(int i=0;i<k;i++)
		{
			//scic(ch,dam);
			scanf(" %c",&ch);
			sci(dam);
			save[ch]=dam; //দাম কত 
		}
		
		ans=0.0;
		sci(m);
		getchar();
		while(m--)
		{
			gets(str);
			int len=strlen(str);
			for(int i=0;i<len;i++)
			{
				ans+=save[str[i]]; //others is 0.
			}
		}
		printf("%.2lf$\n",(ans)/100.0); //value is in cents.
	}
	return 0;
}
