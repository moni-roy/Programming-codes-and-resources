#include<bits/stdc++.h>
using namespace std;
int main()
{
	double n1, num,ans;
	long long cas=0;
	while(cin>>num)
	{
		if(num==0) break;
		n1=(3.0+sqrt((9.0+4.0*2*num)))/2.0;
		ans=ceil(n1);
		cout<<"Case "<<++cas<<": ";
		printf("%.0lf\n",ans);
	}
	return 0;
}
