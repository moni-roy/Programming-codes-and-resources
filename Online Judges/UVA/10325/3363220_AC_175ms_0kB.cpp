#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[20],n,m,tl,lcm,cnt,evn;
int main()
{
	while(cin>>n>>m){
		
		for(int i=0;i<m;i++) cin>>a[i];
		cnt=0;
		for(int i=1;i<(1<<m);i++)
		{
			lcm=1;evn=0;
			for(int j=0;j<m;j++)
			{
				//cout<<(1<<j)<<" "<<(i&(1<<j))<<" "<<i<<" "<<j<<endl;
				if(i&(1<<j))
				{
					evn++;
					lcm=(lcm*a[j])/__gcd(lcm,a[j]);
				}
			}
			tl=n/lcm;
			if(evn%2) cnt+=tl;
			else cnt-=tl;
		}
		cout<<n-cnt<<endl;
	}
}
