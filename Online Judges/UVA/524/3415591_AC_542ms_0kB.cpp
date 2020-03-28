#include <bits/stdc++.h>
using namespace std;
typedef int ll;
ll a[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
map<ll,ll>prm;
ll n,sv[100],vs[100],p[100],cs=0;
void prim()
{
    prm[2]=1;
    for(int i=3;i<50;i+=2)
    {
        if(vs[i]==0)
        {
            prm[i]=1;
            for(int j=i+i;j<50;j+=i)
            {
                vs[j]=1;
            }
        }
    }
}
void print()
{
    cout<<1;
    for(int i=1;i<n;i++)
    {
        cout<<" "<<p[i];
    }
    cout<<endl;
}
void fun(ll ps,ll pr)
{
    if(ps==n)
    {
        int t=1+p[n-1];
        if(prm[t]==1)
        {
            print();
        }
        return ;
    }
    for(int i=1;i<n;i++)
    {
        if(sv[i]==0)
        {
            if(prm[a[i]+a[pr]]==1)
            {
                sv[i]=1;
                p[ps]=a[i];
                fun(ps+1,i);
                sv[i]=0;
            }
        }
    }
}
int main()
{
    prim();
    while(cin>>n)
    {
        if(cs) cout<<endl;
        cout<<"Case "<<++cs<<":"<<endl;
        sv[0]=1;
        p[0]=1;
        fun(1,0);
    }
    return 0;
}
