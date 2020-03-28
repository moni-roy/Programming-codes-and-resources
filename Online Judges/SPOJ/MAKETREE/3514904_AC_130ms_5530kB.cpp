#include <bits/stdc++.h>
using namespace std;
int n,m,p,x,ok[100100],ans[100100],v,u;
vector<int>sv[100100],as;

int main()
{
	//cin>>n>>m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		//cin>>p;
		scanf("%d",&p);
		for(int j=0;j<p;j++)
		{
			scanf("%d",&x);
			sv[i].push_back(x);
			ok[x]++;
		}
	}
	queue<int>q;
	for(int i=1;i<=n;i++)
	{
		if(ok[i]==0) q.push(i);
	}
	while(!q.empty())
	{
		u=q.front();q.pop();
		as.push_back(u);
		for(int i=0;i<(int)sv[u].size();i++)
		{
			v=sv[u][i];
			ok[v]--;
			if(ok[v]==0) q.push(v);
		}
	}
	ans[as[0]]=0;
	for(int i=1;i<n;i++)
	{
		ans[as[i]]=as[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",ans[i]);
	}
}
