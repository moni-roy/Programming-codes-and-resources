#include<bits/stdc++.h>
#define ld double
#define ll long long int
#define scldd(x,y) scanf("%lf%lf",&x,&y)
#define scld(x) scanf("%lf",&x)
#define scll(x,y) scanf("%lld%lld",&x,&y)
#define scl(x) scanf("%lld",&x)
#define scal(x,y,c,s) scanf("%lld%lld %c %s",&x,&y,&c,s)
#define sclll(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)

using namespace std;

bool taut(char str[])
{
	int len=strlen(str);
	char ch=str[0];
	for(int i=1;i<len-1;i++)
	{
		if(str[i]==' ')
		{
			if(str[i+1]!=ch)
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	char str[10009];
	while(gets(str))
	{
		if(str[0]=='*') break;
		int ln=strlen(str);
		//int cnt=0;
		for(int i=0;i<ln;i++)
		{
			if(str[i]>='A'&&str[i]<='Z')
			{
				str[i]=str[i]-'A'+'a';
				//cnt++;
			}
		}
		
		if(taut(str)==1) puts("Y");
		else puts("N");
	}
	return 0;
}
