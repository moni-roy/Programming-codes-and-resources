#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[1000001],t,m,n,cs=0,d,ln,mn,flg,k;

int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&n,&m,&k);
        ll mp[1005];
        mn=n;
        x[1]=1;
        x[2]=2;
        x[3]=3;
        int i,j=1;
        d=0;
        ln=0;
        flg=0;
        memset(mp,0,sizeof mp);
        for( i=1; i<=n; i++)
        {
            if(i>3) x[i]=(x[i-1]+x[i-2]+x[i-3])%m+1;
            if(mp[x[i]]==0&&x[i]<=k)
            {
                d++;
            }
            ln++;
            mp[x[i]]++;
            if(d==k)
            {
                flg=1;
                mn=min(mn,ln);
            }
            while(d>=k)
            {
                if(d==k) mn=min(mn,ln);
                mp[x[j++]]--;
                ln--;
                if(mp[x[j-1]]==0&&x[j-1]<=k) d--;
            }
        }
        printf("Case %lld: ",++cs);
        if(flg) printf("%lld\n",mn);
        else puts("sequence nai");
    }

    return 0;
}
