#include<bits/stdc++.h>
using namespace std;
vector<int>node[200];
int sc,ttl,cas=0;
int bfs(int idx)
{
    queue<int>mk;
    mk.push(idx);
    int visit[1000]={0};
    visit[idx]=1;
    while(!mk.empty())
    {
        int u=mk.front();
        for(int i=0;i<node[u].size();i++)
        {
            int v=node[u][i];
            if(!visit[v])
            {
               if(visit[u]==2)
               {
                visit[v]=1;
			   }
			   else visit[v]=2;
			   
               mk.push(v);
            }
            if(visit[v]==visit[u]) return 0;
        }
        mk.pop();
    }
    return 1;
}
int main()
{
    int num,x,n,y,i;
    while(cin>>num&&num)
    {
		cin>>n;
        map<int,int>my;
        //int n1,n2,k;
        for(i=0;i<n;i++)
        {
            cin>>x>>y;
            node[x].push_back(y);
            node[y].push_back(x);
        }
        int mk=bfs(0);
        if(mk==1) puts("BICOLORABLE.");
        else puts("NOT BICOLORABLE.");
        for( i=0;i<num;i++)
        {
            node[i].clear();
        }
    }
    return 0;
}
