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
#define scss(x,y) scanf("%s %s",x,y)
#define scs(x) scanf("%s",x)
#define scc(x) scanf("%c ",&x)

using namespace std;

int main()
{
	char ch,num[110],cop[110];
	
	while(scanf(" %c %s",&ch,num)==2)
	{
		//scc(ch);
		//scs(num);
		if(ch=='0'&&num[0]=='0') break;
		int len = strlen(num);
		int j=0;
		for(int i=0;i<len;i++)
		{
			if(num[i]!=ch)
			{
				cop[j++]=num[i];
			}
		}
		cop[j]='\0';
		int i=0;
		while(cop[i++]=='0');
		int sl=strlen(cop);
		if(i==sl+1||sl==0)
		{
			printf("0");
			goto mk;
		}
		for(int m=i-1;m<sl;m++)
		{
			printf("%c",cop[m]);
		}
	mk:
	puts("");
}
return 0;
}
