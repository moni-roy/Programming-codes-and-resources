#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dl double

int main()
{
	dl v1,v2,v3,a1,a2,BirdDistance,d;
	int t,cs=0;
	cin>>t;
	while(t--)
	{
		cin>>v1>>v2>>v3>>a1>>a2;
		dl t1,t2;
		t1=v1/a1;
		t2=v2/a2;
		if(t1>t2)
		{
			BirdDistance=t1*v3;
		}
		else BirdDistance=t2*v3;
		d=(v1*t1-0.5*a1*t1*t1)+(v2*t2-0.5*a2*t2*t2);
		cout<<"Case "<<++cs<<": ";
		printf("%.10lf %.10lf\n",d,BirdDistance);
	}
	return 0;
}
