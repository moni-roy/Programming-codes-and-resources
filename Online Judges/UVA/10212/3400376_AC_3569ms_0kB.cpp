#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,b,as,mn;
ll BMOD(ll x,ll p,ll md)
{
    ll ret=1;
    while(p>0)
    {
        if(p&1) ret=(ret*x)%md;
        p/=2;
        x=(x*x)%md;
    }
    return ret;
}
int main()
{
    while(cin>>n>>m)
    {
        ll cnt2=0,cnt5=0;
        as=1;
        for(int i=n-m+1;i<=n;i++)
        {
            b=i;
            while(b%2==0)
            {
                b/=2;
                cnt2++;
            }
            while(b%5==0)
            {
                b/=5;
                cnt5++;
            }
            as*=b;
            //cout<<as<<endl;
            as%=10;
        }
        mn=abs(cnt2-cnt5);
        if(mn)
        {
            if(cnt2>cnt5) as*=BMOD(2ll,mn,10ll);
            else as*=BMOD(5ll,mn,10ll);
            as%=10;
        }
        cout<<as<<endl;
    }
    return 0;
}
