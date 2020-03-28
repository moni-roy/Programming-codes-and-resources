#include<bits/stdc++.h>
#define LL long long int

using namespace std;

LL lucky(LL nm)
{
	LL real=0,digit,rem=0;
	while(nm>0)
	{
		digit=nm%10;
		if(digit==4||digit==7)
		{
			real=real*10+digit;
		}
		nm/=10;
	}
	LL retn=0;
	while(real>0)
	{
		rem=real%10;
		retn=retn*10+rem;
		real/=10;
	}
	return retn;
}

int main()
{
	LL a,b,c;
	while(cin>>a>>b)
	{
		int flag=1;
		while(flag)
		{
			a++;
			if(lucky(a)==b)
			{
				c=a;
				flag=0;
			}
		}
		
		cout<<c<<endl;
	}
	return 0;
}
