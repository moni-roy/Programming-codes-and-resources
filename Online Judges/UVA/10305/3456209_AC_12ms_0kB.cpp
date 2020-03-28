#include <bits/stdc++.h>
using namespace std;
int m,n,ok[101],vs[101],x,y,sv[101][101];

void fun()
{
    queue<int>q;
    vector<int>as;
    for(int i=1; i<=n; i++)
    {
        if(ok[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        as.push_back(u);
        for(int i=1; i<=n; i++)
        {
            if(sv[u][i]==1)
            {
                ok[i]--;
                if(ok[i]==0) q.push(i);
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        if(i!=0) cout<<' ';
        cout<<as[i];
    }
    cout<<endl;
}
int main()
{
    while(cin>>n>>m)
    {
if(m==0&&n==0) break;
        memset(ok,0,sizeof ok);
        memset(sv,0,sizeof sv);

        for(int i=0; i<m; i++)
        {
            cin>>x>>y;
            ok[y]++;
            sv[x][y]=1;
        }
        fun();
    }
    return 0;
}