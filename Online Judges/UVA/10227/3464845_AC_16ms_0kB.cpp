#include <bits/stdc++.h>
using namespace std;
int t,x,y,ans,p,T,par[1000],sv[110][110];
char s[100];
int FND(int p)
{
    if(p==par[p]) return p;
    return par[p]=FND(par[p]);
}
void make_set(int i,int j)
{
    int u=FND(i);
    int v=FND(j);
    if(v!=u)
    {
        ans--;
        par[v]=u;
    }
}
bool same(int i,int j)
{
    for(int k=0;k<T;k++)
    {
        if(sv[i][k]!=sv[j][k]) return false;
    }
    return true;
}
int main()
{
    cin>>t;
    while(t--)
    {
        memset(sv,0,sizeof sv);
        cin>>p>>T;
        getchar();
        for(int i=0;i<p;i++) par[i]=i;
        while(gets(s)&&sscanf(s,"%d%d",&x,&y)==2)
        {
            sv[x-1][y-1]=1;
        }
        ans=p;
        for(int i=0;i<p-1;i++)
        {
            for(int j=i+1;j<p;j++)
            {
                if(same(i,j))
                {
                    make_set(i,j);
                }
            }
        }
        cout<<ans<<endl;
        if(t) cout<<endl;
    }
}
