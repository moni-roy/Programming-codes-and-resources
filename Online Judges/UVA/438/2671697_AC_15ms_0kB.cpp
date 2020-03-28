#include <bits/stdc++.h>
using namespace std;
#define dl double 
#define pi 3.141592653589793

int main()
{
	dl x,y,p,q,a,b,r;
	while(cin>>a>>b>>x>>y>>p>>q)
	{
		dl m,n,o;
		m=sqrt(((a-x)*(a-x))+((b-y)*(b-y)));
		n=sqrt(((a-p)*(a-p))+((b-q)*(b-q)));
		o=sqrt(((p-x)*(p-x))+((q-y)*(q-y)));
		dl s=(m+n+o)/2;
		r=(m*n*o)/(4*sqrt(s*(s-m)*(s-n)*(s-o)));
		//cout<<m<<' '<<n<<' '<<o<<" "<<s<<' '<<r<<endl;
		printf("%.2lf\n",2*r*pi);
	}
	return 0;
}
