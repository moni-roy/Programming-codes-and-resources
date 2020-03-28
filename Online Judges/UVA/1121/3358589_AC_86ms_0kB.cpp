#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,k,sum,a[100010],id,mn,j;
	while(cin>>n>>k){
	j=0;
	sum=0;
	mn=9999999999;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		while(sum>=k)
		{
			sum-=a[j++];
			if(sum>=k)
			{
				id=i-j+1;
				if(mn>id)
				{
					mn=id;
				}
			}
			if(sum<k) break;
		}
	}
	if(mn==9999999999) cout<<0<<endl;
	else 
		cout<<mn<<endl;
}
}
