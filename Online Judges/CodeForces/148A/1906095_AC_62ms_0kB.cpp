#include<bits/stdc++.h>
#define LL long long int

using namespace std;

int main()
{
	LL k,l,m,n,d,ndm;
	while(cin>>k>>l>>m>>n>>d)
	{
		ndm=0;
		for(LL i=1;i<=d;i++)
		{
			if(i%k==0 || i%l==0 || i%m==0 || i%n==0)
			{
				ndm++;
			}
		}
		//LL damage=d-ndm;
		cout<<ndm<<endl;
	}
	return 0;
}
