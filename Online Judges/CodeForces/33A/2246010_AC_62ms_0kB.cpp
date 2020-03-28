#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll n,i,j,m,k;
    ll arr[1010];
    memset(arr,-1,sizeof arr);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(i=1; i<=n; i++)
    {
        ll x,y;
        scanf("%lld%lld",&x,&y);
        if(arr[x]==-1) arr[x]=y;
        else arr[x]=min(y,arr[x]);
    }
    ll sum=0;
    for(i=1; i<=m; i++)
    {
        sum+=arr[i];
    }
    if(sum>=k) cout<<k<<endl;
    else cout<<sum<<endl;
    return 0;
}
