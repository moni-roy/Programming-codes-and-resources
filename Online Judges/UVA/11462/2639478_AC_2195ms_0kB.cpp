#include <bits/stdc++.h>
using namespace std;
int n,ar[2000009],ag;

void merge(int st, int mid, int en)
{
	vector<int>lf,rg;
	for(int i=st;i<=mid;i++) lf.push_back(ar[i]);
	for(int i=mid+1;i<=en;i++) rg.push_back(ar[i]);
	lf.push_back(9999999);
	rg.push_back(9999999);
	int p1=0,p2=0;
	for(int i=st;i<=en;i++)
	{
		if(lf[p1]<rg[p2])
		{
			ar[i]=lf[p1++];
		}
		else ar[i]=rg[p2++];
	}
	return ;
}
void divide(int st, int en)
{
	if(st==en) return;
	int mid = (st+en)/2;
	divide(st,mid);
	divide(mid+1,en);
	merge(st,mid,en);
}

int main()
{
	while(cin>>n&&n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>ar[i];
		}
		divide(0,n-1);
		cout<<ar[0];
		for(int i=1;i<n;i++)
		{
			cout<<' '<<ar[i];
		}
		cout<<endl;
				
	}
	return 0;
}
	
