#include <bits/stdc++.h>
#define ll long long
#define D double

using namespace std;
struct data
{
    ll k;
    D dis;
};
bool cmp(data a, data b)
{
    return a.dis<b.dis;
}
int main()
{
    data mk[1010];
    ll num,pop;
    ll mln=1000000;
    cin>>num>>pop;
    ll x[1010],y[1010];
    //double dis[1010];
    for(ll i=0; i<num; i++)
    {
        cin>>x[i]>>y[i]>>mk[i].k;
        mk[i].dis=sqrt((double)(x[i]*x[i])+(double)(y[i]*y[i]));
     //   cout<<mk[i].dis<<endl;
    }
    sort(mk,mk+num,cmp);
    double ans;
    //cout<<endl;
//    for(int i=0;i<num;i++)
//    {
//        cout<<mk[i].dis<<' '<<mk[i].k<<endl;
//    }
//    cout<<endl;
    for(ll i=0; i<num; i++)
    {
    //    cout<<mk[i].k<<" "<<mk[i].dis<<endl;
        pop+=mk[i].k;
        if(pop>=mln)
        {
            ans=mk[i].dis;
            break;
        }
    }
    if(pop<mln) cout<<"-1"<<endl;
    else
    {
        printf("%.10lf\n",ans);
    }
    return 0;
}
