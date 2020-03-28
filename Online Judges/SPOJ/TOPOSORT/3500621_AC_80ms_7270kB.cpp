#include <bits/stdc++.h>
using namespace std;
int n,p,ok[1000001],x,y;
vector<int>as,sv[11010];
int main()
{
	//cin>>n>>p;
	scanf("%d%d",&n,&p);
	for(int i=0;i<p;i++)
	{
		//cin>>x>>y;
		scanf("%d%d",&x,&y);
		sv[x].push_back(y);
		ok[y]++;
	}
	priority_queue<int>q;
	for(int i=1;i<=n;i++)
	{
		if(ok[i]==0) q.push(-1*i);
	}
	while(!q.empty())
	{
		int u=-1*q.top();
		q.pop();
		as.push_back(u);
		for(int i=0;i<(int)sv[u].size();i++)
		{
			int v=sv[u][i];
			ok[v]--;
			if(ok[v]==0) q.push(-1*v);
		}
	}
	if((int)as.size()!=n) puts("Sandro fails.");
	else
	{
		for(int i=0;i<(int)as.size();i++)
		{
			if(i==0) printf("%d",as[i]);
			else printf(" %d",as[i]);
		}
		puts("");
	}
}
