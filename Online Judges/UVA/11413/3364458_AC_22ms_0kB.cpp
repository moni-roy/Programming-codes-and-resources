#include <bits/stdc++.h>
using namespace std;
long long n,k,sum,hi,lw,a[1000010],mid,cap,dv,res;
long long fun(int m)
{
    long long int cnt=0;
    for(int i=0; i<n; i++)
    {
        if(cap+a[i]<=mid)
        {
            cap+=a[i];
        }
        else
        {
            cap=a[i];
            cnt++;
        }
        if(mid<a[i])
        {
            return k;
        }
    }
    return cnt;
}
int main()
{
    while(cin>>n>>k)
    {
        sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        hi=99999999999;
        lw=0;
        res=hi;
        while(lw<=hi)
        {
            mid=(lw+hi)>>1;
            cap=0;

            dv=fun(mid);

            if(dv<k)
            {
                res=min(res,mid);
                hi=mid-1;
            }
            else
            {
                lw=mid+1;
            }
        }
        cout<<res<<endl;
    }
}
