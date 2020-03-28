#include <bits/stdc++.h>
using namespace std;
int main()
{
	int ts,n,a,x,y,es,hd;
	cin>>ts;
	while(ts--)
	{
		cin>>n>>x>>y;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			if(i==0) es=a;
			if(i==n-1) hd=a;
		}
		if(es==x&&hd==y) cout<<"BOTH"<<endl;
		else if(es==x) cout<<"EASY"<<endl;
		else if(hd==y) cout<<"HARD"<<endl;
		else cout<<"OKAY"<<endl;
	}
	return 0;
}
