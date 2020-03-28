#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sn,d,n,grid[1026][1026],x,y,idx,idy,sx,sy,wt,mx;
int main()
{
	cin>>sn;
	while(sn--)
	{
		memset(grid,0,sizeof grid);
		cin>>d>>n;
		for(int i=0;i<n;i++)
		{
			cin>>x>>y>>wt;
			sx=x-d;
			sy=y-d;
			if(sx<0) sx=0;
			if(sy<0) sy=0;
			for(int p=sx;p<=x+d&&p<1026;p++)
			{
				for(int o=sy;o<=y+d&&o<1026;o++)
				{
					grid[p][o]+=wt;
				}
			}
		}
		mx=0;
		for(int i=0;i<=1025;i++)
		{
			for(int j=0;j<=1025;j++)
			{
				if(mx<grid[i][j])
				{
					mx=grid[i][j];
					idx=i;
					idy=j;
				}
			}
		}
		cout<<idx<<" "<<idy<<" "<<mx<<endl;
	}
}
/*
1
1
2
4 4 10
6 6 20
* */
