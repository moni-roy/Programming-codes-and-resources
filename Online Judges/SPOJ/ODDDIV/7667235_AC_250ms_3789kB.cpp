#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define mx 1050
#define lm 100010

ll prime[mx],a[mx+5],k;
int prime_sieve()
{
    ll i,j,k=0,lmt;
    a[0]=a[1]=1;
    for(i=4; i<=mx; i+=2)
        a[i]=1;
    lmt=sqrt(mx);
    for(i=3; i<=lmt; i+=2)
    {
        if(!a[i])
        {
            for(j=i*i; j<=mx; j+=2*i)
            {
                a[j]=1;
            }
        }

    }
    prime[k++]=2;
    for(i=3; i<=mx; i+=2)
    {
        if(!a[i])
        {
            prime[k++]=i;
        }
    }
}
vector<ll>dn[10005];
void div()
{
    prime_sieve();

    ll i,j,count,ds=1;
    i=1;
    for(i=0;i<10005;i++)
        dn[i].push_back(0);
    for(i=1;i<=lm;i++)
    {
        ds=1;
        ll tmp=i;
        for(j=0;prime[j]*prime[j]<=tmp;j++)
        {
            count=0;
            if(tmp%prime[j]==0)
            {
                while(tmp%prime[j]==0)
                {
                    tmp/=prime[j];
                    count++;
                }
                ds*=(2*count+1);
            }
        }
        if(tmp!=1)
            ds*=3;
       dn[ds].push_back(i*i);
    }
}
ll left_indx(ll a)
{
    ll i,mid,left,right;
    left=0;
    right=dn[k].size()-1;
    while((left+1)<right)
    {
        mid=(left+right)/2;
        if(a>dn[k][mid])
            left=mid+1;
        else
            right=mid;
    }
    return right;
}
ll right_indx(ll a)
{
    ll i,mid,left,right;
    left=1;
    right=dn[k].size();
    while((left+1)<right)
    {
        mid=(left+right)/2;
        if(a<dn[k][mid])
            right=mid-1;
        else
            left=mid;
    }
    return left;
}


int main()
{

    div();
    int i;

    ll tc;
    cin>>tc;
    while(tc--)
    {
        ll a,b,count;
        cin>>k>>a>>b;
ll n=upper_bound(dn[k].begin(),dn[k].end(),b)-dn[k].begin();
ll m=lower_bound(dn[k].begin(),dn[k].end(),a)-dn[k].begin();
       count=n-m;
       cout<<count<<endl;
    }
    return 0;
}