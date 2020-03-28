#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,mn,as,x,a[1000010],cnt,t;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		for(int i=0;i<m;i++)
		{
			cin>>a[i];
		}
		
		for(int i=0;i<n;i++)
		{
			cin>>x;
			mn=999999999;
			as=999999999;
			for(int j=0;j<m;j++)
			{
				cnt=__builtin_popcountl(x^a[j]);
				//cout<<cnt<<" "<<mn<<endl;
				if(cnt<mn)
				{
					mn=cnt;
					as=a[j];
				}
				else if(cnt==mn)
				{
					as=min(as,a[j]);
				}
			}
			cout<<as<<endl;
		}
	}
}
