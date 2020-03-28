#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>prm;
ll vs[1000001],num[1000001];
void fun()
{
    memset(vs,0,sizeof vs);
    prm.push_back(2);
    for(int i=3; i<47000; i+=2)
    {
        if(vs[i]==0)
        {
            prm.push_back(i);
            for(int j=i+i; j<47000; j+=i)
            {
                vs[j]=1;
            }
        }
    }
}
int main()
{
    ll n,cnt,mx;
    fun();
    while(cin>>n&&n)
    {
        cnt=0;
        ll c=n;
        n=abs(n);
        mx=0;
        int k=0;
        for(int i=0; i<prm.size()&&(prm[i]*prm[i])<=n; i++)
        {
            if(n%prm[i]==0)
            {
                cnt=0;
                while(n%prm[i]==0)
                {
                    n/=prm[i];
                    cnt++;
                }
                mx=__gcd(cnt,mx);
            }
        }
        if(n>1)
        {
            mx=__gcd(1ll,cnt);
        }
        if(c<0)
        {
            while(mx%2==0) mx/=2;
        }
        cout<<mx<<endl;
    }

}
/*
400
*/
/*
2
*/
