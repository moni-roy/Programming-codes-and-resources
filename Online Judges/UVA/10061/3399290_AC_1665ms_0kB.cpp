#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int vs[1000010],m,n,b,k,cn,cb,cnt,mn,as;
vector<int>prm;

void fun()
{
    prm.push_back(2);
    for(int i = 3; i < 1200; i += 2)
    {
        if(vs[i] == 0)
        {
            prm.push_back(i);
            for(int j = i + i; j < 1200; j += i)
            {
                vs[j] = 1;
            }
        }
    }
}
int main()
{
    fun();
    while(cin >>n>>b)
    {
        cn=n;
        cb=b;
        map<int,int>mp;
        double bs=0.0;
        for(int i = 2; i<=n; i++)
        {
            int p=i;
            for(int j=0; prm[j]*prm[j]<=p; j++)
            {
                if(p%prm[j]==0)
                {
                    while(p%prm[j]==0)
                    {
                        p/=prm[j];
                        mp[prm[j]]++;
                    }
                }
            }
            if(p>1) mp[p]++;
        }
        mn=9999999;
        for(int i = 0; i < (int)prm.size() && prm[i]*prm[i] <= b; i++)
        {
            if(b % prm[i] == 0)
            {
                cnt = 0;
                while(b % prm[i] == 0)
                {
                    b /= prm[i];
                    cnt++;
                }
                mn=min(mn,(mp[prm[i]]/cnt));
            }
        }
        if(b > 1)  mn=min(mn,mp[b]);

        map<int,int>::iterator it;
        for(it=mp.begin(); it!=mp.end(); it++)
        {
            bs+=(log10(it->first*1.0)*it->second);
        }
        as=bs/log10(cb);
        as++;
        cout<<mn<<" "<<as<<endl;
    }
}
