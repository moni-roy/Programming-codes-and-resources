#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>prm;
ll vs[100010],cm,cn,m,n,cnt,k,pw,sv[10001];

void fun()
{
    memset(vs,0,sizeof vs);
    prm.push_back(2);
    for(int i=3; i<47000; i+=2)
    {
        if(!vs[i])
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
    fun();
    while(scanf("%lld %lld",&n,&m)==2)
    {
        k=0;
        cm=m;
        cn=n;
        pair<ll,ll>pr[1000];
        for(int i=0; i<prm.size()&&prm[i]*prm[i]<=m; i++)
        {
            if(m%prm[i]==0)
            {
                cnt=0;
                while(m%prm[i]==0)
                {
                    cnt++;
                    m/=prm[i];
                }
//                pr[k]=make_pair(prm[i],cnt);
                pr[k].first=prm[i];
                pr[k].second=cnt;
                k++;
            }
        }
        if(m>1)
        {
//            pr[k]=make_pair(m,1);
            pr[k].first=m;
            pr[k].second=1;
            k++;
        }
        ll flg=0;
        for(int i=0;i<k;i++)
        {
            cnt=0;
            ll p=pr[i].first;
            pw=1;
            while(pw<n)
            {
                pw*=p;
                cnt+=(n/pw);
                if(cnt>=pr[i].second) break;
            }
            if(cnt<pr[i].second)
            {
                flg=1;
                break;
            }
        }
        if(flg==1||cm==0)
        {
            printf("%lld does not divide %lld!\n",cm,cn);
        }
        else printf("%lld divides %lld!\n",cm,cn);
    }
    return 0;
}
