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

int n,k,a[1000001],idx;
deque< int >dq,qq;
void maxsld()
{
	int i;
	idx=0;
	for( i=0;i<k;i++)
	{
		while(!dq.empty() && a[dq.back()]<a[i])
		{
			dq.pop_back();
		}
		dq.push_back(i);
	}
	for(;i<n;i++)
	{
		printf("%d ",a[dq.front()]);
		while(!dq.empty()&&dq.front()<=(i-k))
		{
			dq.pop_front();
		}
		while(!dq.empty() && a[dq.back()]<a[i])
		{
			dq.pop_back();
		}
		dq.push_back(i);
	}
	
	printf("%d ",a[dq.front()]);
}
void minsld()
{
	//deque< int >qq(k);
	int i;
	idx=0;
	for( i=0;i<k;i++)
	{	
		while(!qq.empty() && a[qq.back()]>a[i])
		{
			qq.pop_back();
		}
		qq.push_back(i);
	}
	for(;i<n;i++)
	{	
		printf("%d ",a[qq.front()]);
		while(!qq.empty()&&qq.front()<=(i-k))
		{
			qq.pop_front();
		}
		while(!qq.empty() && a[qq.back()]>a[i])
		{
			qq.pop_back();
		}
		qq.push_back(i);
	}

	printf("%d ",a[qq.front()]);
}
	
int main()
{
	while(scanf("%d%d",&n,&k)!=EOF){
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		minsld();
		puts("");
		maxsld();
		puts("");
	}
	return 0;
}
