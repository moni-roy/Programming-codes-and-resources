#include<bits/stdc++.h>
#define ll long long

using namespace std;
ll path[333][333];
int main()
{
    ll num;
    cin>>num;
    for(ll i=1;i<=num;i++)
    {
        for(ll j=1;j<=num;j++)
        {
            cin>>path[i][j];
        }
    }
    ll qry,x,y,dis;
    cin>>qry;
    ll save[305];
    for(ll k=0;k<qry;k++)
    {
        cin>>x>>y>>dis;
        ll sum=0;
        for(ll i=1;i<=num;i++)
        {
            for(ll j=i+1;j<=num;j++)
            {
                path[i][j]=min(path[i][j],path[i][x]+dis+path[y][j]);
                path[i][j]=path[j][i]=min(path[i][j],path[i][y]+dis+path[x][j]);
                sum+=path[i][j];
            }
        }
        save[k]=sum;
    }
    for(ll k=0;k<qry;k++)
    {
        cout<<save[k]<<" ";
    }
    cout<<endl;
    return 0;
}
