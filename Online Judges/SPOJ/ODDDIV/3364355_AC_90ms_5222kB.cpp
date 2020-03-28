#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sq,cnt,x,y,sx,sy,t,ans,k,vis[100001];
vector<ll>prm,v[100010];

void fun()
{
    memset(vis,0,sizeof vis);
    prm.push_back(2);
    for(int i=3;i<=1000;i+=2)
    {
        if(vis[i]==0)
        {
            prm.push_back(i);
            vis[i]=1;
            for(int j=i+i;j<=1000;j+=i)
            {
                vis[j]=1;
            }
        }
    }
	for(int i=2;i<=100000;i++)
	{
	    ans=1,cnt=0;
	    sq=i;
		for(int j=0;sq>=prm[j]*prm[j];j++)
        {
            cnt=0;
            while(sq%prm[j]==0)
            {
                cnt++;
                sq/=prm[j];
            }
            if(cnt>0) ans*=((cnt<<1)+1);
        }
        if(sq>1) ans*=3;
        v[ans>>1].push_back((ll)i*i);
	}
}

int main()
{
	fun();

	scanf("%lld",&t);
	while(t--)
	{
	    vector<ll>::iterator l,h;
		scanf("%lld%lld%lld",&k,&x,&y);

        k>>=1;
        l=lower_bound(v[k].begin(),v[k].end(),x);
        h=upper_bound(v[k].begin(),v[k].end(),y);

		printf("%lld\n",(ll)(h-l));
	}
}
