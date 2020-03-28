///Doom’s Day
#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long t,cs=0,m,n;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		cout<<"Case "<<++cs<<": ";
		if(n==m) cout<<2<<endl;
		else 
			cout<<(m+n)/__gcd(m,n)<<endl;
	}
}
