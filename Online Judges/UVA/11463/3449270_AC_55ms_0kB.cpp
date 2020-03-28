#include <bits/stdc++.h>
using namespace std;
#define inf 999999999
int n,p,sv[101][101],x,y,st,en,mx,cs=0,t;
void fun()
{
    for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
        sv[i][j]=min(sv[i][j],sv[i][k]+sv[k][j]);
    }
}

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>p;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                sv[i][j]=(i==j)?0:inf;
            }
        }
        for(int i=0;i<p;i++)
        {
            cin>>x>>y;
            sv[x][y]=1;
            sv[y][x]=1;
        }
        fun();
        mx=0;
        cin>>st>>en;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,sv[st][i]+sv[i][en]);
        }
        cout<<"Case "<<++cs<<": "<<mx<<endl;
    }
}
