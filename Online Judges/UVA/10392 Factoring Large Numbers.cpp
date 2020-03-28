#include <bits/stdc++.h>
using namespace std;
bool vs[10001000];
vector<long long>prm;
void sieve()
{
    prm.push_back(2);
    for(int i=3; i<=1000001; i+=2)
    {
        if(vs[i]==false)
        {
            prm.push_back(i);
            for(int j=i+i; j<=1000001; j+=i)
                vs[j]=true;
        }
    }
}

int main()
{
    sieve();
    long long int n;
    while(scanf("%lld",&n)==1)
    {
        if(n<0) break;
        long long cn=n,cnt=0;
        long long int mx=0;
        for(int i=0; i<(int)prm.size() && prm[i]*prm[i]<=n; i++)
        {
            if(n%prm[i]==0)
            {
                while(n%prm[i]==0)
                {
                    n/=prm[i];
                    printf("    %lld\n",prm[i]);
                }
            }
        }
        if(n>1)
        {
            printf("    %lld\n",n);
        }
        puts("");
    }
    return 0;
}

