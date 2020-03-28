#include<stdio.h>
#include<math.h>

int main()
{
	long long t,T,k;
	double tax;

	scanf("%lld",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%lld",&k);

		if(k<=180000)
		{
			tax=0.0;
		}
		else if(k<480000)
		{
			tax=(k-180000)*1.0/10.0;
			if(tax<2000)
			{
				tax=2000.0;
			}
		}
		else if(k<=880000)
		{
			tax=(30000+((k-480000)*15.0/100));
		}
		else if(k<=1180000)
		{
			tax=90000+(k-880000)*1.0/5;
		}
		else
		{
			tax=150000+(k-1180000)*1.0/4;
		}

		printf("Case %lld: %.0lf\n",t,ceil(tax));
	}
	return 0;
}
