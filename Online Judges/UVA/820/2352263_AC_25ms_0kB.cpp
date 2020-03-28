/// Max-flow algorithm
/// using Edmonds-karp algorithm

#include <bits/stdc++.h>
#define ll long long
#define MX 101

using namespace std;

int crnt[MX],cap[MX][MX],flw[MX][MX],prnt[MX];
vector<int>graph[MX];
int bfs(int st, int en)
{
	memset(prnt,-1,sizeof prnt);
	memset(crnt,0,sizeof crnt);
	queue<int>q;
	q.push(st);
	prnt[st]=-2;
	crnt[st]=2147483646;
	while(!q.empty())
	{
		int cnt=q.front();q.pop();
		for(int i=0;i<graph[cnt].size();i++)
		{
			int next=graph[cnt][i];
			if(prnt[next]==-1)
			{
				if(cap[cnt][next]-flw[cnt][next]>0)
				{
					prnt[next]=cnt;
					crnt[next]=min(crnt[cnt],cap[cnt][next]-flw[cnt][next]);
					//cout<<next<<' '<<prnt[next]<<' '<<crnt[next]<<' '<<cap[cnt][next]-flw[cnt][next]<<endl;
					if(next==en) return crnt[en];
					q.push(next);
				}
			}
		}
	}
	return 0;
}
int edmonds_karp(int st,int en)
{
	int maxflow=0;
	while(true)
	{
		int flg=bfs(st,en);
		if(flg==0)
		{
			break;
		}
		//cout<<flg<<endl;
		maxflow+=flg;
		int cnt=en;
		while(cnt!=st)
		{
			int prv=prnt[cnt];
			flw[cnt][prv]-=flg;
			flw[prv][cnt]+=flg;
			//cout<<cnt<<' '<<prv<<' '<<flw[cnt][prv]<<' '<<flw[prv][cnt]<<endl;
			cnt=prv;
		}
	}
	return maxflow;
}
int main()
{
	int nd,st,en,pr,cas=0;
	while(cin>>nd&&nd)
	{
		memset(flw,0, sizeof flw);
		memset(cap,0, sizeof cap);
		cin>>st>>en>>pr;
		//if(cas!=0) cout<<endl;
		int frm,to,bnd;
		for(int i=0;i<pr;i++)
		{//cout<<st<<' '<<en<<' '<<pr<<' '<<i<<endl;
			cin>>frm>>to>>bnd;
			cap[frm][to]+=bnd;
			cap[to][frm]+=bnd;
			graph[frm].push_back(to);
			graph[to].push_back(frm);
		}
		int ans=edmonds_karp(st,en);
		//if(cas!=0) cout<<endl;
		cout<<"Network "<<++cas<<endl;
		cout<<"The bandwidth is "<<ans<<"."<<endl<<endl;
		for(int i=0;i<MX;i++)
		{
		graph[i].clear();
	}
	}
	return 0;
}