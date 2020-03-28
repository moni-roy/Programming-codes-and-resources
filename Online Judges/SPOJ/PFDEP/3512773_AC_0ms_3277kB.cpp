#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,k,u,v,ok[200];
vector<int>sv[200],as;
int main()
{
	while(cin>>n>>m)
	{
		memset(ok,0,sizeof ok);
		//memset(ok,o,sizeof ok);
		while(m--){
			cin>>x>>k;
			for(int i=0;i<k;i++)
			{
				cin>>y;
				ok[x]++;
				sv[y].push_back(x);
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
			as.push_back(u);
			for(int i=0;i<(int)sv[u].size();i++)
			{
				v=sv[u][i];
				ok[v]--;
				if(ok[v]==0) q.push(-1*v);
			}
		}
		for(int i=0;i<(int)as.size();i++)
		{
			if(i==0) cout<<as[i];
			else cout<<" "<<as[i];
		}
		cout<<endl;
		for(int i=0;i<=n;i++) {
			sv[i].clear();
		}
		as.clear();
	}
}
