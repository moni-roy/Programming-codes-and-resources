#include <bits/stdc++.h>
using namespace std;
bool vs[10001000];
vector<long long>prm;
void sieve()
{
    prm.push_back(2);
    for(int i=3; i<=10000001; i+=2)
    {
        if(vs[i]==false)
        {
            prm.push_back(i);
            for(int j=i+i; j<=10000001; j+=i)
                vs[j]=true;
        }
    }
}

int main()
{
    sieve();
//    cout<<prm.size()<<" "<<prm[prm.size()-1]<<endl;
    long long int n;
    while(scanf("%lld",&n)==1)
    {
        if(n==0) break;
        long long cn=n,cnt=0;
        long long int mx=0;
        if(n<0) n*=-1;
        for(int i=0; i<(int)prm.size() && prm[i]*prm[i]<=n; i++)
        {
            if(n%prm[i]==0)
            {
                while(n%prm[i]==0)
                {
                    n/=prm[i];
                }
                mx=max(mx,(long long)prm[i]);
                cnt++;
            }
        }
        if(n>1)
        {
            cnt++;
            mx=max(mx,n);
        }
        if(1>=cnt)
        {
            puts("-1");
        }
        else printf("%lld\n",mx);
    }
    return 0;
}
