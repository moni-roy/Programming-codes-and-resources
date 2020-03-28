#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define dl double
#define pi 2*acos(0.0)

int main()
{
	int tst;
	string st;
	dl r1,r2,t,ar;
	cin>>tst;
	getchar();
	while(tst--)
	{
		int a[20];
		int i=0,m;
		getline(cin,st);
		stringstream ss;
		ss<<st;
		///cout<<ss<<endl;
		while(ss>>m)
		{
			a[i]=m;
			i++;
		}
		//cout<<a[1]<<' '<<a[0]<<endl;
		if(i==1)
		{
			t=a[0];
			ar=(pi*(t/2)*(t/2))-2*((t/4.0)*pi*(t/4.0));
		}
		else
		{
			r1=a[0];
			r2=a[1];
			dl r=((2*r1)+(2*r2))/2.0;
			ar=(r*r*pi)-(pi*r1*r1)-(pi*r2*r2);
		}
		printf("%.4lf\n",ar);
	}
	return 0;
}
			
