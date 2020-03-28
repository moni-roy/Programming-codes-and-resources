#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll num;
    ll ar[10000],i=0,flag=0;
    while(cin>>num&&num!=0)
    {
        flag=0;
        for(i=0; i<num; i++)
        {
            ll nm;
            cin>>nm;
            ar[i]=nm;
        }
        sort(ar,ar+num);
        ar[num]=1422;
        for(ll j=1; j<num; j++)
        {
            if((ar[num]-ar[num-1])>100)
            {
                flag=1;
                goto mk;
            }
            if((ar[j]-ar[j-1])>200)
            {
                flag=1;
                goto mk;
            }
        }
        mk:
        if(flag) cout<<"IMPOSSIBLE"<<endl;
        else cout<<"POSSIBLE"<<endl;
    }
    return 0;
}
