#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n,a[1010101],k;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>k;
	int mx=0;
	for(int i=0;i<k;i++)
	{
		mx=max(mx,a[i]);
	}
	for(int i=0;i<n-k+1;i++)
	{
		if(a[i+k-1]>mx)
		{
			mx=a[i+k-1];
		}
		else if(mx==a[i-1])
		{
			mx=a[i];
			for(int j=i+1;j<i+k;j++)
			{
				mx=max(mx,a[j]);
			}
		}
		cout<<mx<<' ';
	}
	cout<<endl;
	return 0;
}
