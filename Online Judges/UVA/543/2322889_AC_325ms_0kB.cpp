#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll prime(ll x)
{
    if(x<=2) return 0;
    if(x%2==0) return 0;
    for(ll i=3;i<=sqrt(x);i+=2)
    {
        if(x%i==0) return 0;
    }
    return 1;
}
int main()
{
    ll num,fst,snd;
    while(cin>>num)
    {
        if(num==0) break;
        ll flg=0;
        for(ll i=3;i<=num;i++)
        {
            if(prime(i)==1&&prime(num-i)==1)
            {
                fst=i;
                snd=num-i;
                flg=1;
                break;
            }
        }
        if(flg==0) cout<<"Goldbach's conjecture is wrong."<<endl;
        else
        {
            cout<<num<<" = "<<fst<<" + "<<snd<<endl;
        }
    }
    return 0;
}
