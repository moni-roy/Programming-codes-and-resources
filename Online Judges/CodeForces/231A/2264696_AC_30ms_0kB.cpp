#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll ar[1010];
int main()
{
    ll num;
    cin>>num;

    ll fst,snd,trd;
    for(ll i=0;i<num;i++)
    {
        cin>>fst>>snd>>trd;
        if(fst==1) ar[i]++;
        if(snd==1) ar[i]++;
        if(trd==1) ar[i]++;
    }
    ll cnt=0;
    for(ll i=0;i<num;i++)
    {
        if(ar[i]>=2)
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
