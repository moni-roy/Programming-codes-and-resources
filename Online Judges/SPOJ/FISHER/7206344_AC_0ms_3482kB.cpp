#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long
#define inf (1e14)
ll n,T,tl[55][55],cs[55][55],ds[55],sv[55];

int main()
{
    while(cin>>n>>T)
    {
		if(n==0 && T==0) break;
		
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                cin>>cs[i][j];
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                cin>>tl[i][j];
            }
        }
        ll AnsTL=inf,AnsT;
        priority_queue<pair<ll,pii > , vector<pair<ll,pii> >, greater<pair<ll,pii > > > pq;
        
        memset(sv,-1,sizeof sv);
        pq.push({0,{0,1}});
        while(!pq.empty())
        {
            int u = pq.top().second.second;
            int t = pq.top().first;
            int tm = pq.top().second.first;
            if(u==n){
				AnsTL=t;
				AnsT=tm;
				break;
			}
			pq.pop();
			if(sv[u]==-1||tm<sv[u]){
				sv[u]=tm;
				for(int i=1; i<=n; i++)
				{
					if(i!=u)
					{
						if(tm+cs[u][i]<=T)
						{
							pq.push({t+tl[u][i],{tm+cs[u][i],i}});
						}
					}
				}
			}
        }
        cout<<AnsTL<<" "<<AnsT<<endl;
    }
    return 0;
}
/*
4 7
0 5 2 3
5 0 2 3
3 1 0 2
3 3 2 0

0 2 2 7
2 0 1 2
2 2 0 5
7 2 5 0

*/
