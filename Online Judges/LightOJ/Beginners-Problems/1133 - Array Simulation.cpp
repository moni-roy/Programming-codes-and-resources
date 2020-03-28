#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	ll t,cs=0,n,m,a[100001],x,y;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		char ch;
		for(int i=0;i<m;i++)
		{
			cin>>ch;
			if(ch=='P')
			{
				cin>>x>>y;
				swap(a[x],a[y]);
			}
			else if(ch=='R')
			{
				for(int i=0;i<n/2;i++)
				{
					swap(a[i],a[n-1-i]);
				}
			}
			else if(ch=='D')
			{
				cin>>x;
				for(int i=0;i<n;i++)
				{
					a[i]/=x;
				}
			}
			else if(ch=='M')
			{
				cin>>x;
				for(int i=0;i<n;i++)
				{
					a[i]*=x;
				}
			}
			else
			{
				cin>>x;
				for(int i=0;i<n;i++)
				{
					a[i]+=x;
				}
			}
		}
		cout<<"Case "<<++cs<<":"<<endl;
		cout<<a[0];
		for(int i=1;i<n;i++)
		{
			cout<<' '<<a[i];
		}
		cout<<endl;
	}
	return 0;
}
