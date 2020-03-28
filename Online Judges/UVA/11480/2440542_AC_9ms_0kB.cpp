#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ll n,cs=0;
	while(cin>>n&&n)
	{
		ll sum=0;
		for(int i=1;;i++)
		{
			if(3*i>=n) break;
			sum+=(n-3*i-1)/2;
		}
		cout<<"Case "<<++cs<<": ";
		cout<<sum<<endl;
	}
	return 0;
}
/*
 * 0 < r < b < g
 * (b-r)+(g-r)=n-3*r
 * 
 * r--> (n-3r-1)/2;
 * 
 * (-1) for b==g (invlid)
 * 
 * */
