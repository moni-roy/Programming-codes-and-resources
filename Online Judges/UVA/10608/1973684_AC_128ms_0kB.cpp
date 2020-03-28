#include<bits/stdc++.h>

using namespace std;
vector<int >adj[30001];
int visit[30001];
int cnt;
void dfs(int pos)
{
	int tmp;
	cnt++;
	visit[pos]=1;
	for(int i=0;i<adj[pos].size();i++)
	{
		tmp=adj[pos][i];
		if(visit[tmp]==0) dfs(tmp);
	}
}
int main()
{
	int tst,mx,num,pair,x,y;
	cin>>tst;
	while(tst--)
	{
		mx=0;
		//memset(visit,0,sizeof(visit));
		cin>>num>>pair;
		for(int i=0;i<num;i++)
		{
			adj[i].clear();
			visit[i]=0;
		}
		for(int i=0;i<pair;i++)
		{
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		for(int i=0;i<num;i++)
		{
			if(visit[i]==0)
			{
				cnt=0;
				dfs(i);
				mx=max(mx,cnt);
			}
		}
		cout<<mx<<endl;
	}
	return 0;
}
