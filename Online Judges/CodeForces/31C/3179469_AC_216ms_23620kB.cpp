#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,cnt,i,j,st[1000001],en[1000001],in[1000001];
vector<ll>v;
int main()
{
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>st[i]>>en[i];
    }
    cnt=0;
    //memset()
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(st[i]>=en[j]||st[j]>=en[i])
            {
                //nothing to do
            }
            else
            {
                cnt++;
                in[i]++;
                in[j]++;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(in[i]==cnt)
        {
            v.push_back(i);
        }
    }
    cout<<v.size()<<endl;
    for(i=0;i<(ll)v.size();i++)
    {
        cout<<v[i]+1<<' ';
    }
    cout<<endl;
    return 0;
}
