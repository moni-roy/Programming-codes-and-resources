#include<bits/stdc++.h>
using namespace std;
int n,u,v,pos[200010],a[200010],vs[200010];
vector<int> graph[200010];

int main()
{    
    cin>>n;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
        pos[a[i]]=i;
    }
    for(int i = 1;i<=n;i++){
        sort(graph[i].begin(),graph[i].end(),[](int a,int b){
            return (pos[a]<pos[b]);
        });
    }
    queue<int>q;
    q.push(1);
    vs[1] = 1;
    int k = 0;
    while (!q.empty())
    {
        u = q.front();q.pop();
        if(a[k++]!=u) {
            cout<<"NO"<<endl;
            return 0;
        }
        for(auto v: graph[u]){
            if(vs[v]==0){
                vs[v]=1;
                q.push(v);
            }
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
