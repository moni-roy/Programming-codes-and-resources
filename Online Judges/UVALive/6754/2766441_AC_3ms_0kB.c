#include <stdio.h>
#include <string.h>
#include <math.h>
#define mod 1000000007

int main()
{
	int ts;
	char s[10010];
	scanf("%d",&ts);
	while(ts--)
	{
		scanf("%s",s);
		int sz=strlen(s);
		int i,check=-1;
		long long ans=1,cnt=0;
		for(i=0;i<sz;i++)
		{
			if(s[i]!='?')
			{
				if(s[i]-'a'!=check&&check!=-1)
				{
					ans=(ans*(cnt+1))%mod;
					
				}
				cnt=0;
				check=s[i]-'a';
			}
			else cnt++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
	
