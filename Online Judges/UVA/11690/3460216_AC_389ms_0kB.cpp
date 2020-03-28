#include <bits/stdc++.h>
using namespace std;
int t,m,n,x,y,ar[10001],par[10001],flg;
int FND(int i)
{
    if(par[i]==i) return i;
    return par[i]=FND(par[i]);
}
void make_set(int i,int j)
{
    int u=FND(i);
    int v=FND(j);
    if(u!=v)
    {
//        if(ar[u]>0)
//        {
//            if(ar[v]<0)
//            {
//                ar[u]=ar[u]+ar[v];
//                ar[v]=0;
//            }
//        }
//        else if(ar[u]<0)
//        {
//            if(ar[v]>0)
//            {
//                ar[u]=0;
//                ar[v]=ar[v]+ar[u];
//            }
//        }
        ar[v]=ar[u]+ar[v];
        ar[u]=0;
        par[u]=v;
    }
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0; i<n; i++)
        {
            cin>>ar[i];
            par[i]=i;
        }
        for(int i=0; i<m; i++)
        {
            cin>>x>>y;
            make_set(x,y);
        }
        flg=0;
        for(int i=0; i<n; i++)
        {
            if(ar[i]!=0)
            {
                flg=1;
                break;
            }
        }
        if(flg) cout<<"IMPOSSIBLE"<<endl;
        else cout<<"POSSIBLE"<<endl;
    }
}
