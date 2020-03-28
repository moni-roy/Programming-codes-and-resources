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
        sort(v,v+k);
        ll j=1;
        for(ll i=k-1;i>=0;i--)
        {
            sum=sum+(2*pow(v[i],j));
            j++;
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
