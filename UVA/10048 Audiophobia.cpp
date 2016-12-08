#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int u,v,w;
	bool operator <(const edge &p)const
	{
		return w<p.w;
	}
};
int pr[103],a[109][109];
vector<edge>eg;
int FIND(int p)
{
	return (pr[p]==p)? p:pr[p]=FIND(pr[p]);
}
vector<int>V[109];
void mst(int n)
{
	sort(eg.begin(),eg.end());
	for(int i=0;i<=n+5;i++) pr[i]=i;
	int cnt=0,sum=0;
	for(int i=0;i<(int)eg.size();i++)
	{
		int u=FIND(eg[i].u);
		int v=FIND(eg[i].v);
		if(u!=v)
		{
			if(u<v) pr[v]=u;
			else pr[u]=v;
			V[u].push_back(v);
			V[v].push_back(u);
			a[u][v]=a[v][u]=eg[i].w;
		}
	}
}
bool vs[102];
int pr2[101];
void cost(int x,int y)
{
    vs[x]=1;
    for(int i=0;i<(int)V[x].size();i++){
        int xx=V[x][i];
        if(!vs[xx]){
            vs[xx]=1;
            pr2[xx]=x;
            if(xx==y) return;
            cost(xx,y);
        }
    }
    return;
}
int main()
{
	int tst,cs=0,n,m,q;
    while(scanf("%d%d%d",&n,&m,&q)==3)
    {
        if(!n && !m && !q) break;
        edge get;
        for(int i=1; i<=m; i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            get.u=x;
            get.v=y;
            get.w=z;
            eg.push_back(get);
        }
        mst(n);
        if(cs) puts("");
		printf("Case #%d\n",++cs);
		while(q--){
            int x,y;
            scanf("%d%d",&x,&y);
            if(FIND(x)!=FIND(y)) puts("no path");
            else{
                memset(vs,0,sizeof vs);
                cost(x,y);
                int Ans=0;
                while(x!=y){
                    Ans=max(Ans,a[y][pr2[y]]);
                    y=pr2[y];
                }
                printf("%d\n",Ans);
            }
		}
		eg.clear();
		for(int i=0;i<=n;i++) V[i].clear();
	}
	return 0;
}

