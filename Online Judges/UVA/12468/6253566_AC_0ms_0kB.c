#include<stdio.h>
int main()
{
	int a,b,output;
	while(scanf("%d %d",&a,&b)==2)
	{
		if(a<0&&b<0)
		{
			break;
		}
		else if(a>=0&&a<=99&&b>=0&&b<=99)
		{
			if(a<b)
			{
				if(b-a>=50)
				{
					a=a+100;
					output=a-b;
					printf("%d\n",output);
				}
				else
				{
					output=b-a;
					printf("%d\n",output);
				}
			}
			else
			{
				if(a-b>=50)
				{
					b=b+100;
					output=b-a;
					printf("%d\n",output);
				}
				else
				{
					output=a-b;
					printf("%d\n",output);
				}
			}
		}
	}
	return 0;
}