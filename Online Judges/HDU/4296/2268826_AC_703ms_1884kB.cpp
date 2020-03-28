#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define ll long long
#define scll(x) scanf("%I64d",&x)
using namespace std;
typedef struct data{
ll w,s;
};
bool cmp(data a, data b)
{
    return a.w+a.s<b.w+b.s;
}
int main()
{
    ll num;
    while(scll(num)==1)
    {
        data mk[101010];
        for(ll i=0;i<num;i++)
        {
            scll(mk[i].w);
            scll(mk[i].s);
        }
        sort(mk,mk+num,cmp);
        ll sum=0,ans=0;
        for(ll i=0;i<num;i++)
        {
            //cout<<mk[i].s<<' '<<mk[i].w<<endl;
            ans=max(ans,sum-mk[i].s);
            sum+=mk[i].w;
        }
        if(ans<0) ans=0;
        printf("%I64d\n",ans);
    }
return 0;
}
