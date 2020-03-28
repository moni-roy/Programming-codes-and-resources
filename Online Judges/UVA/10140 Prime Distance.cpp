#include <bits/stdc++.h>
using namespace std;
bool vs[1000100];
vector<int>prm;
void sieve()
{
    prm.push_back(2);
    vs[1]=1;
    for(int i=4;i<=1000009;i+=2) vs[i]=true;
    for(int i=3; i<=1000009; i+=2)
    {
        if(vs[i]==false)
        {
            prm.push_back(i);
            for(int j=i+i; j<=1000009; j+=i)
                vs[j]=true;
        }
    }
}

int main()
{
    sieve();
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int Anx,Any,Amy,Amx;
        if(m<=1000001)
        {
            int l=lower_bound(prm.begin(),prm.end(),n)-prm.begin();
            int h=lower_bound(prm.begin(),prm.end(),m)-prm.begin();
            if(prm[h]!=m) h--;
            int mn=999999999;
            int mx=0;
            if(h-l+1<=1){
                puts("There are no adjacent primes.");
                continue;
            }
            for(int i=l+1;i<=h;i++)
            {
                int ds=prm[i]-prm[i-1];
                if(ds>mx){
                    mx=ds;
                    Amx=prm[i-1];
                    Amy=prm[i];
                }
                if(ds<mn){
                    mn=ds;
                    Anx=prm[i-1];
                    Any=prm[i];
                }
            }
            printf("%d,%d are closest, %d,%d are most distant.\n",Anx,Any,Amx,Amy);
            continue;
        }
        bool sv[1000100];
        vector<int> Ans;
        for(int i=0;i<=m-n;i++){
            sv[i]=false;
        }
        if(n==1) sv[0]=1;
        int sq=sqrt(m);
        for(int i=2;i<=sq;i++){
            if(vs[i]==false){
                int t;
                if(n%i==0) t=max(i*i,n);
                else t=max(i*i,n+(i-n%i));
                for(int j=t;j>=n && j<=m;j+=i) sv[j-n]=true;
            }
        }
        for(int i=0;i<m-n+1;i++){
            if(sv[i]==false){
                Ans.push_back(i+n);
            }
        }
        int l=lower_bound(Ans.begin(),Ans.end(),n)-Ans.begin();
        int h=lower_bound(Ans.begin(),Ans.end(),m)-Ans.begin();
        if(Ans[h]!=m) h--;
        int mn=999999999;
        int mx=0;
        if(h-l+1<=1)
        {
            puts("There are no adjacent primes.");
            continue;
        }
        for(int i=l+1; i<=h; i++)
        {
            int ds=Ans[i]-Ans[i-1];
            if(ds>mx)
            {
                mx=ds;
                Amx=Ans[i-1];
                Amy=Ans[i];
            }
            if(ds<mn)
            {
                mn=ds;
                Anx=Ans[i-1];
                Any=Ans[i];
            }
        }
        printf("%d,%d are closest, %d,%d are most distant.\n",Anx,Any,Amx,Amy);

    }
    return 0;
}

