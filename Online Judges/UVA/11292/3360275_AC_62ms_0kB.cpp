#include <bits/stdc++.h>
using namespace std;

int main()
{
	int h,k,aa[100001],a[100001],l,j,sum=0;
	while(cin>>h>>k)
	{
		if(h+k==0) break;
		for(int i=0;i<h;i++) cin>>a[i];
		for(int i=0;i<k;i++) cin>>aa[i];
		sort(a,a+h);
		sort(aa,aa+k);
		l=0;
		j=0;
		sum=0;
		while(l<h)
		{
			if(a[l]<=aa[j])
			{
				sum+=aa[j];
				j++;
				l++;
			}
			else
				j++;
			if(j>=k) break;
		}
		if(j<=k&&l==h) cout<<sum<<endl;
		else cout<<"Loowater is doomed!"<<endl;
	}
	return 0;
}
