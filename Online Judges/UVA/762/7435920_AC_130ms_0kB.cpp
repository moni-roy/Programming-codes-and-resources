#include<bits/stdc++.h>

using namespace std;

int visited[1000007];
map<string,int>indx;
vector<int>adj[1000007];
vector<string>city[1000007];
int parent[1000007];
vector<int>route;

int bfs(int s,int dstn)
{
    memset(visited,0,sizeof(visited));
    memset(parent,0,sizeof(parent));
    queue<int>Q;
    Q.push(s);
    visited[s]=1;
    parent[s]=0;
    while(!Q.empty())
    {
        int u= Q.front();
        Q.pop();
        int i,v;

        if(u==dstn)
        {
            return 1;
        }
        for(i=0; i<adj[u].size(); i++)
        {
            v = adj[u][i];
            if(visited[v]==0)
            {
                visited[v]=1;
                parent[v]=u;
                Q.push(v);
            }
        }
    }
    return 0;
}
int main()
{
    int tc=0,i,n;
    string src,dstn;
    while(scanf("%d",&n)==1)
    {
        if(tc)   cout<<endl;
        tc++;
        int cnt=1;

        indx.clear();
        for(i=0; i<1000000; i++)
            adj[i].clear();
        for(i=0; i<1000000; i++)
            city[i].clear();
        route.clear();


        string first,second;

        for(i=1; i<=n; i++)
        {
            cin>>first>>second;

            if(indx[first]==0)
            {
                indx[first]=cnt++;
                city[indx[first]].push_back(first);
            }
            if(indx[second]==0)
            {
                indx[second]=cnt++;
                city[indx[second]].push_back(second);

            }
            adj[indx[first]].push_back(indx[second]);
            adj[indx[second]].push_back(indx[first]);
        }
        cin>>src>>dstn;

        int j,s;

        if(indx[src]&&indx[dstn])
        {
            if(bfs(indx[src],indx[dstn]))
            {
                s=indx[dstn];
                while(parent[s])
                {
                    route.push_back(s);
                    s=parent[s];
                }
                route.push_back(indx[src]);

                for(i = route.size()-1; i>0; i--)
                {
                    cout<<city[route[i]][0]<<" "<<city[route[i-1]][0]<<endl;
                }

            }
            else
            {
                cout<<"No route"<<endl;
            }
        }
        else
            cout<<"No route"<<endl;


    }
    return 0;
}
