#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int test,n,a,d,sum=0;
	cin>>test;
	while(test--)
	{
		cin>>n>>a>>d;
		sum=a;
		long long int ans=a;
		for(long long int i=1;i<n;i++)
		{
			sum=sum+d;
			ans=ans+sum;
		}
		cout<<ans<<endl;
	}
	return 0;
}
