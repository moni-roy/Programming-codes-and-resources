#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,ar[1000],ag;
	while(cin>>n&&n)
	{
		memset(ar,0,sizeof ar);
		int m=0;
		for(int i=0;i<n;i++)
		{
			cin>>ag;
			ar[ag]++;
			m=max(m,ag);
		}
		int k=1,a=0;
		while(k<=m)
		{
			while(ar[k]>0)
			{
				cout<<k;
				ar[k]--;
				a++;
				if(a<n)
				{cout<<' ';}
			}
			k++;
		}
		cout<<endl;
				
	}
	return 0;
}
	
