#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long y,k,n;
	cin>>y>>k>>n;
	int flag=0;
	for(long long i=1;i<=n;i++)
	{
		if(i*k>n) break;
		else if((i*k-y)<=0) continue;
			flag=1;
			cout<<i*k-y<<' ';
	}
	if(!flag) cout<<"-1";
	cout<<endl;
	//main();
	return 0;
}
