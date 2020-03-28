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
    ll x,y,cas=0;
    while(scll(x,y)==2)
    {
        if(x==0 && y==0) break;
        if(x==0||x==1)
        {
            cout<<"Case "<<++cas<<": ";
            printf(":-\\\n");
        }
        else if(x<=y)
        {
            cout<<"Case "<<++cas<<": ";
            puts(":-|");
        }
        else
        {
            cout<<"Case "<<++cas<<": ";
            puts(":-(");
        }
    }
    return 0;
}
