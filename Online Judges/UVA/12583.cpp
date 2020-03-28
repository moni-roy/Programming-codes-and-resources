#include<iostream>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

#include<cmath>
#include<cstdio>

#define MOD 1000003
#define LL long long
#define LLU long long unsigned
#define PB push_back
#define SCL(x) scanf("%d",&x)
#define SCLL(x) scanf("%lld",&x)

using namespace std;
int mx(int x,int y)
{
	return x>y?x:y;
}

int main()
{
	int tst,day,cas=0,mn;
	string nm;
	cin>>tst;
	while(tst--)
	{
		cin>>day>>mn>>nm;
		//int len = nm.length();
		int ans=0;
		for(int i=0;i<day;i++)
		{
			for(int j=i-1;j>=mx(0,i-mn);j--)
			{
				if(nm[j]==nm[i]) 
				{
					ans++;
					break;
				}
			}
		}
		cout<<"Case "<<++cas<<": "<<ans<<endl;
	}
	return 0;
}
