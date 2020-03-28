#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long unsigned llu;
ll n,m,mn,i,id;
map<ll,ll>mp;
int main()
{
    cin>>n;
    mn=9999999999;
    for(i=0;i<n;i++)
    {
        cin>>m;
        mp[m]++;
        if(m<mn)
        {
            id=i+1;
            mn=m;
        }
    }
    if(mp[mn]==1) cout<<id<<endl;
    else cout<<"Still Rozdil"<<endl;
}
