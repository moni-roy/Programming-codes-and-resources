#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll t,cs=0,A,B;
	cin>>t;
	while(t--)
	{
		cin>>A>>B;
		if(A<=1)
		{
			A=0;
		}
		else
		{
			A=A-2-(A-2)/3;
		}
		if(B<=1)
		{
			B=0;
		}
		else
		{
			B=B-1-(B-1)/3;
		}
		cout<<"Case "<<++cs<<": "<<B-A<<endl;
	}
	return 0;
}
