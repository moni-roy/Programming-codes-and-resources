#include<stdio.h>
#include<string.h>

int main()
{
	char num[1000001];
	long long int i,a4,b4,a15,a100,a400,a55,b100,b15,b400,b55,count=0;
	
	while(NULL!=gets(num))
	{
		b4=0;b100=0;b15=0;b55=0;b400=0;
		
		if(count>0)
		{ 
			printf("\n");
		}
		count++;
		
		for(i=0;i<strlen(num);i++)
		{
			a4=(b4*10)+(num[i]-'0');
			a100=(b100*10)+(num[i]-'0');
			a400=(b400*10)+(num[i]-'0');
			a15=(b15*10)+(num[i]-'0');
			a55=(b55*10)+(num[i]-'0');
			b4=a4%4;
			b400=a400%400;
			b100=a100%100;
			b15=a15%15;
			b55=a55%55;
		}
		if(b4==0 && b100!=0 || b400==0)
		{
			printf("This is leap year.\n");
			
			if(b15==0)
			{
				printf("This is huluculu festival year.\n");
			}
			if(b55==0)
			{
				printf("This is bulukulu festival year.\n");
			}
		}
		else if(b15==0)
		{
			printf("This is huluculu festival year.\n");
		}
		else
		{
			printf("This is an ordinary year.\n");
		}
	}
	return 0;
}	
