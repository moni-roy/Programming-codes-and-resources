#include <bits/stdc++.h>
using namespace std;
int as[200],ok[200],x,y,u,m,n,mx,idx;
vector<int>sv[200];
int main()
{
	while(cin>>n)
	{
		if(n==0) break;
		
		for(int i=1;i<=n;i++)
		{
			cin>>m;
			for(int j=0;j<m;j++)
			{
				cin>>y;
				ok[i]++;
				sv[y].push_back(i);
			}
		}
		priority_queue<int>q;
		for(int i=1;i<=n;i++)
		{
			if(ok[i]==0) q.push(-1*i);
		}
		while(!q.empty())
		{
			u=-1*q.top();q.pop();
			for(int i=0;i<(int)sv[u].size();i++)
			{
				int v=sv[u][i];
				ok[v]--;
				if(ok[v]==0) q.push(-1*v);
				as[v]=as[u]+1;
			}
		}
		mx=0;
		for(int i=1;i<=n;i++)
		{
			if(mx<as[i])
			{
				idx=i;
				mx=as[i];
			}
		}
		cout<<idx<<endl;
		for(int i=0;i<=n;i++)
		{
			sv[i].clear();
			ok[i]=0;
			as[i]=0;
		}
	}
}
