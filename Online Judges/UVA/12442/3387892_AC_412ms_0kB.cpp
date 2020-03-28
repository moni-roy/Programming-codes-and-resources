#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int t,cs=0,n,u,v,c,vs[55000],adj[55000],cnt,sv[55000],vv[55000];

int fun(int s)
{
    if(sv[s]!=0)
    {
        return 0;
    }
    vs[adj[s]]=1;
    sv[s]= 1;
    c=1+fun(adj[s]);
    sv[s]=0;
    return c;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(vs,0,sizeof vs);
        //memset(vv,0,sizeof vv);
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&u,&v);
            adj[u]=v;
        }
        cnt=0;
        int mx=0,id;
        for(int i=1; i<=n; i++)
        {
            if(vs[i]==0)
            {
                //memset(sv,0,sizeof sv);
                c=0;
                vs[i]=1;
                cnt=fun(i);
                if(cnt>mx)
                {
                    id=i;
                    mx=cnt;
                }
            }
        }
        printf("Case %d: %d\n",++cs,id);
    }
    return 0;
}
