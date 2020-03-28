#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,ar[1000],nl=0;
	while(cin>>n&&n!=0)
	{
		if(nl++) cout<<endl;
		for(int i=0;i<n;i++)
		{
			cin>>ar[i];
		}
		for(int i=0;i<n-5;i++)
		{
			for(int j=i+1;j<n-4;j++)
			{
				for(int k=j+1;k<n-3;k++)
				{
					for(int p=k+1;p<n-2;p++)
					{
						for(int q=p+1;q<n-1;q++)
						{
							for(int x=q+1;x<n;x++)
							{
								if(ar[x]>ar[q]&&ar[q]>ar[p]&&ar[p]>ar[k]&&ar[k]>ar[j]&&ar[j]>ar[i])
								{
									cout<<ar[i]<<' '<<ar[j]<<' '<<ar[k]<<' '<<ar[p]<<' '<<ar[q]<<' '<<ar[x]<<endl;
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
