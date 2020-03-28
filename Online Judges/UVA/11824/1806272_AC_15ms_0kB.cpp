#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll tst,num,sum;
    cin>>tst;
    while(tst--)
    {
        ll v[100],k=0;
        while(cin>>num&&num!=0)
        {
            v[k]=num;
            k++;
        }
        sum=0;
//        ll lm=v.size();
        sort(v,v+k);
//        set<ll>::iterator it;
//        it=v.end();
        ll j=1;
//        while(it!=v.begin())
        for(ll i=k-1;i>=0;i--)
        {
            sum=sum+(2*pow(v[i],j));
            j++;
//            it--;
        }
        if(sum>5000000)
        {
            cout<<"Too expensive"<<endl;
        }
        else
        {
            cout<<sum<<endl;
        }
    }
    return 0;
}
