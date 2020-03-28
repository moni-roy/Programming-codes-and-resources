#include <bits/stdc++.h>
using namespace std;
#define llu long long unsigned

int main()
{
	llu n;
	while(cin>>n&&n)
	{
		if(n%9==0)
		{
			cout<<(n+n/9-1)<<' '<<n+n/9<<endl;
		}
		else
		{
			cout<<n+n/9<<endl;
		}
	}
	return 0;
}
