#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>prm;
ll vs[1000001];
void fun()
{
    memset(vs,0,sizeof vs);
    prm.push_back(2);
    for(int i=3; i<150000; i+=2)
    {
        if(vs[i]==0)
        {
            prm.push_back(i);
            for(int j=i+i; j<150000; j+=i)
            {
                vs[j]=1;
            }
        }
    }
}
int main()
{
    ll n,cn;
    fun();
    while(cin>>n)
    {
        ll i=0,tt=n,c=n,fc=1;
        for(int i=0;i<prm.size()&&prm[i]*prm[i]<=n;i++)
        {
            if(n%prm[i]==0)
            {
                cn=0;
                while(n%prm[i]==0)
                {
                    n/=prm[i];
                    cn++;
                }
                tt/=prm[i],tt*=(prm[i]-1);
                fc*=(cn+1);
            }
        }
        if(n>1)
        {
            tt/=n;
            tt*=(n-1);
            fc*=2;
        }
        cout<<c-tt-fc+1<<endl;
    }
}
