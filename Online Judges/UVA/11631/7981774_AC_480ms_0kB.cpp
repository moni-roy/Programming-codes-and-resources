
// uva 11631
#include<bits/stdc++.h>
using namespace std;
#define MX 200007
long long costAll=0,cost=0;
long long par[MX+7];
struct node{
    long long a,b,cost;
};
node a[MX+7];
bool cmp(node u,node v){
    if(u.cost<v.cost) return true;
    else return false;
}

int Find(int r)
{
    if(par[r]==r) return r;
    else{
        return par[r]=Find(par[r]);
    }
}


int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        if(m==0 && n==0)break;
        long long u,v,w;
		costAll = 0;
        for(int i=0;i<n;i++){
            cin>>u>>v>>w;
            a[i].a=u;
            a[i].b=v;
            a[i].cost=w;
            costAll+=w;
        }
        //cout<<costAll<<endl;

        // sorting
        sort(a,a+n,cmp);
        //
        for(int i=0;i<n;i++)par[i]=i;
		cost = 0;
        for(int i=0;i<n;i++)
        {
            int p_u=Find(a[i].a);
            int p_v=Find(a[i].b);
            if(p_v != p_u)
            {
                par[p_u]=p_v;
                cost+=a[i].cost;
            }
        }
        cout<<costAll-cost<<endl;
    }

    return 0;
}
