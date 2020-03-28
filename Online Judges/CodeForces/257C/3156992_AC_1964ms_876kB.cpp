#include <bits/stdc++.h>
using namespace std;
typedef double dl;
typedef long long ll;
typedef long long unsigned llu;
#define pi acos(-1.0)
dl a,b,ag,mx,sv[111111];
ll n,i;
dl rdn_to_dgr(dl an)
{
	return (an*180.0)/(pi);
}
int main()
{
	//cout<<pi<<endl;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a>>b;
		ag=asin(abs(b)/(sqrt(abs(a)*abs(a)+abs(b)*abs(b))));
		ag=rdn_to_dgr(ag);
		if(a<0&&b>=0) ag=180.0-ag;
		else if(a>=0&&b<0) ag=360.0-ag;
		else if(a<0&&b<0) ag=180.0+ag;
		sv[i]=ag;
	}
	sort(sv,sv+n);
	mx=360.0-sv[n-1]+sv[0];
	//cout<<sv[n-1]<<"___"<<sv[0]<<endl;
	//cout<<mx<<endl;
	for(int i=1;i<n;i++)
	{
		
		mx=max(mx,sv[i]-sv[i-1]);
		//cout<<mx<<"++"<<sv[i]-sv[i-1]<<endl;
	}
	//cout<<360.0-mx<<endl;
	printf("%.8lf\n",360-mx);
}
