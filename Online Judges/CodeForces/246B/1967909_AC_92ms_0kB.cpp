#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long num,ar,sum=0;
	cin>>num;
	for(long long i=0;i<num;i++)
	{
		cin>>ar;
		sum+=ar;
	}
	if(sum%num==0)
	{
		cout<<num<<endl;
	}
	else
	{
		cout<<num-1<<endl;
	}
	
	//main();
	return 0;
}
