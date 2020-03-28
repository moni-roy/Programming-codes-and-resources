#include <stdio.h>
#include <string.h>
int max(int x,int y)
{
	return x<y?y:x;
}
int main()
{
	int sum[1001][1001],a[1001][1001],ts,m,n,i,j,tmp;
	scanf("%d",&ts);
	while(ts--)
	{
		scanf("%d%d",&m,&n);
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
				scanf("%d",&a[i][j]);
		long long int ans=-123456789;
		memset(sum,0,sizeof sum);
		for(i=m;i>=1;i--) {tmp=0;
			for(j=n;j>=1;j--){
				tmp+=a[i][j];
				sum[i][j]=(sum[i+1][j]+tmp);
				ans=max(ans,sum[i][j]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

