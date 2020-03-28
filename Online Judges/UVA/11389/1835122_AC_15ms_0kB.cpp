/*---------------------------------------------------------.
 *                                                          *
 * Team-phoenix of JU                                       *
 *             Powered by RUM@HELP                          *
 * _________________________________________________________*/
#include<bits/stdc++.h>
#define ld double
#define ll long long int
#define llu long long unsigned
#define scldd(x,y) scanf("%lf%lf",&x,&y)
#define scld(x) scanf("%lf",&x)
#define scll(x,y) scanf("%lld%lld",&x,&y)
#define scl(x) scanf("%lld",&x)
#define sci(x) scanf("%d",&x)
#define scic(x,y) scanf(" %c %d",&x,&y)
#define scal(x,y,c,s) scanf("%lld%lld %c %s",&x,&y,&c,s)
#define sclll(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define scss(x,y) scanf("%s %s",x,y)
#define sc(s,d,m,y) scanf(" %s %d %d %d",s,&d,&m,&y)

using namespace std;

int main()
{
    ll n,d,r,da[100000],nt[100000],total,dsm,nsm;
    while(sclll(n,d,r)==3)
    {
        if(!(n+d+r)) break;
//        dsm=0;nsm=0;
        total=0;
        for(ll i=0;i<n;i++)
        {
            scl(da[i]);
        }

//        if(dsm>d) total+=(dsm-d)*r;
        for(ll i=0;i<n;i++)
        {
            scl(nt[i]);
        }
        sort(da,da+n);
        sort(nt,nt+n);
        reverse(nt,nt+n);
//        if(nsm>d) total+=(nsm-d)*r;
        for(ll i=0;i<n;i++)
        {
            if((da[i]+nt[i])>d) total+=(da[i]+nt[i])-d;
        }
        cout<<total*r<<endl;
    }
    return 0;
}
