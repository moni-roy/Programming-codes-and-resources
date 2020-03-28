#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n,ok[101],x,y,sv[101][101];
    while(cin>>n>>m)
    {
        if(m==0&&n==0) break;

        memset(ok,0,sizeof ok);
        memset(sv,0,sizeof sv);

        for(int i=0; i<m; i++)
        {
            cin>>x>>y;
            sv[x][y]=1;
            ok[y]++;
        }
        queue<int>q;
        for(int i=1; i<=n; i++)
        {
            if(ok[i]==0) q.push(i);
        }

        vector<int>as;
        while(!q.empty())
        {
            int u=q.front();q.pop();
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

        for(int i=0; i<as.size(); i++)
        {
            if(i!=0) cout<<' ';
            cout<<as[i];
        }
        cout<<endl;
    }
    return 0;
}
