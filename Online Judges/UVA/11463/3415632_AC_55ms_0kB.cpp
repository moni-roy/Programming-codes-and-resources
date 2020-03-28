#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 9999999
vector<int>e[101];
int ok[101],sv[101][101],grp[101][101];
int ts,n,p,st,en,cs=0;
int floyed()
{
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                sv[i][j]=min(sv[i][k]+sv[k][j],sv[i][j]);
            }
        }
    }
}

int main()
{
    cin>>ts;
    while(ts--)
    {
        cin>>n>>p;
        //memset(grp,0,sizeof grp);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                sv[i][j]=(i==j)?0:inf;
            }
        }
        while(p--)
        {
            int u,v;
            cin>>u>>v;
            sv[u][v]=1;
            sv[v][u]=1;
        }
        cin>>st>>en;
        floyed();
        int mx=0;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,sv[st][i]+sv[i][en]);
        }
        cout<<"Case "<<++cs<<": "<<mx<<endl;
    }
}
