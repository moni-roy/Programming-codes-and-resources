#include <bits/stdc++.h>
using namespace std;
#define inf -99999999
int n,st,p,q,mx,idx,cs=0,sv[101][101];
int main()
{
	while(cin>>n)
	{
		if(n==0) break;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				sv[i][j]=(i==j)?0:inf;
			}
		}
		cin>>st;
		while(cin>>p>>q)
		{
			if(p+q==0) break;
			sv[p][q]=1;
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					sv[i][j]=max(sv[i][j],sv[i][k]+sv[k][j]);
				}
			}
		}
		mx=0;
		for(int i=1;i<=n;i++)
		{
			if(mx<sv[st][i])
			{
				idx=i;
				mx=sv[st][i];
			}
		}
		cout<<"Case "<<++cs<<": The longest path from "<<st<<" has length "<<mx<<", finishing at "<<idx<<"."<<endl;
		cout<<endl;
	}
}
/**
5
5
5 1
5 2
5 3
5 4
4 1
4 2
0 0
**/
