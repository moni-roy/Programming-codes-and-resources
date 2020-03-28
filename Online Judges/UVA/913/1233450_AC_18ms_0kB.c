#include<stdio.h>

int main()
{
	unsigned long long od,sum,m;

	while(scanf("%llu",&od)!=EOF)
	{
		m=((od-1)/2)*((od-1)/2);
		sum=(6*(m+od))-9;

		printf("%llu\n",sum);
	}
	return 0;
}
