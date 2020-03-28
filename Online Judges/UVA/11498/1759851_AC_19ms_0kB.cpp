#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long tst,m,n,x,y;
	while(cin>>tst)
	{
		if(tst==0) break;
		cin>>m>>n;
		while(tst--)
		{
			cin>>x>>y;
			if(x==m||y==n) cout<<"divisa"<<endl;
			else if(x>m&&y>n) cout<<"NE"<<endl;
			else if(x<m&&y>n) cout<<"NO"<<endl;
			else if(x>m&&y<n) cout<<"SE"<<endl;
			else cout<<"SO"<<endl;
		}
	}
	return 0;
}
