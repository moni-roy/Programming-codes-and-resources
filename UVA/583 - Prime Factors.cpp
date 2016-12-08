#include <bits/stdc++.h>
using namespace std;
bool vs[100010];
vector<int>prm;
void sieve()
{
    prm.push_back(2);
    for(int i=3; i<=sqrt(2147483648); i+=2)
    {
        if(vs[i]==false)
        {
            prm.push_back(i);
            for(int j=i+i; j<=sqrt(2147483648); j+=i)
                vs[j]=true;
        }
    }
}

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie();
    sieve();
    int n;
    while(scanf("%d",&n)==1)
    {
        if(n==0) break;
        printf("%d = ",n);
        int f=0;
        if(n<0)
        {
            printf("-1");
            f=1;
            n*=-1;
        }
        for(int i=0; i<(int)prm.size() && prm[i]*prm[i]<=n; i++)
        {
            if(n%prm[i]==0)
            {
                while(n%prm[i]==0)
                {
                    if(f==0)
                    {
                        printf("%d",prm[i]);
                        f=1;
                    }
                    else printf(" x %d",prm[i]);
                    n/=prm[i];
                }
            }
        }
        if(n>1)
        {
            if(f)
                printf(" x %d",n);
            else printf("%d",n);
        }
        puts("");
    }
    return 0;
}
