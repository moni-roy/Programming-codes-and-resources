#include <bits/stdc++.h>
using namespace std;
long long int coin[]={1,5,10,25,50};
long long int sv[10][30100];
long long int fun( int ps,long long int n)
{
    if(n==0) return 1;
    if(ps>4||n<0) return 0;
    long long int &ret=sv[ps][n];
    if(ret!=-1) return ret;
    ret=fun(ps,n-coin[ps])+fun(ps+1,n);
    return ret;
}
int main()
{
    long long int n,ans;
    memset(sv,-1,sizeof sv);
    while(cin>>n)
    {
        ans=fun(0,n);
        if(ans==1) cout<<"There is only "<<ans<<" way to produce "<<n<<" cents change."<<endl;
        else cout<<"There are "<<ans<<" ways to produce "<<n<<" cents change."<<endl;
    }
    return 0;
}
