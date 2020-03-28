#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll n,d,ar[1010];
    cin>>n>>d;
    for(ll i=0; i<n; i++)
    {
        cin>>ar[i];
    }
    //sort(ar,ar+n);
    ll cnt=0;
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<n; j++)
        {
            if(i==j) continue;
            ll vl=abs(ar[i]-ar[j]);
            //cout<<vl<<endl;
            if(vl<=d)
            {
                cnt++;
            }
        }

    }
    cout<<cnt<<endl;
    return 0;
}
