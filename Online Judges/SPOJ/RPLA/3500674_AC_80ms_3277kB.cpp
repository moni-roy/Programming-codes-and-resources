#include <bits/stdc++.h>
using namespace std;
int n,p,t,ok[10001],x,y,cs=0;
vector<int>sv[1111];
struct st{
	int rn,nm;
	st(int x,int y)
	{
		nm=x;
		rn=y;
	}
	bool operator<(const st &p) const
	{
		if(rn==p.rn) return nm>p.nm;
		return rn>p.rn;
	}
};
int main()
{
	//cin>>t;
	scanf("%d",&t);
	while(t--)
	{
		//cin>>n>>p;
		scanf("%d%d",&n,&p);
		memset(ok,0,sizeof ok);
		for(int i=0;i<p;i++)
		{
			//cin>>x>>y;
			scanf("%d%d",&x,&y);
			sv[y].push_back(x);
			ok[x]++;
		}
		priority_queue<st>q;
		for(int i=0;i<n;i++)
		{
			if(ok[i]==0) q.push(st(i,1));
		}
		printf("Scenario #%d:\n\n",++cs);
		while(!q.empty())
		{
			st u=q.top();q.pop();
			//cout<<u.rn<<" "<<u.nm<<endl<<endl;
			printf("%d %d\n\n",u.rn,u.nm);
			for(int i=0;i<(int)sv[u.nm].size();i++)
			{
				int v=sv[u.nm][i];
				ok[v]--;
				if(ok[v]==0) q.push(st(v,u.rn+1));
			}
		}
		//if(t) cout<<endl;
		for(int i=0;i<=n;i++) sv[i].clear();
	}
}
