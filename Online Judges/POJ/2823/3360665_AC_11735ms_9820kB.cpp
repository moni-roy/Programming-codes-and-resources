#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>       
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <stack>
#include <deque>

using namespace std;

int n,k,a[1000100];
deque< pair <int, int> >dq,qq;
void maxsld()
{
	for(int i=0;i<n;i++)
	{
		while(!dq.empty()&& dq.back().first<=a[i])
		{
			dq.pop_back();
		}
		dq.push_back(make_pair(a[i],i));
		while(!dq.empty()&&dq.front().second<(i-k+1))
		{
			dq.pop_front();
		}
		if(i>=k-1) printf("%d ",dq.front().first);
	}
	
}
void minsld()
{
	for(int i=0;i<n;i++)
	{
		while(!qq.empty()&&qq.back().first>=a[i])
		{
			qq.pop_back();
		}
		qq.push_back(make_pair(a[i],i));
		while(!qq.empty()&&qq.front().second<(i-k+1))
		{
			qq.pop_front();
		}
		if(i>=k-1) printf("%d ",qq.front().first);
	}
	
}
int main()
{
	//cin>>n>>k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	minsld();
	puts("");
	maxsld();
	puts("");
	return 0;
}
