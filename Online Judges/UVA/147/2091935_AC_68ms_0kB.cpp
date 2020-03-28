#include <bits/stdc++.h>
//#include <iostream>
//#include <algorithm>
//#include <map>
//#include <vector>
//#include <set>
//#include <string>
//
//#include <cstdio>
//#include <cstring>
//#include <cmath>

//#define LL long long int
#define LL long long

using namespace std;
LL coin[]={5,10,20,50,100,200,500,1000,2000,5000,10000};
LL dp[20][40000];
LL func(LL pos,LL rest)
{
	if(rest==0) return 1;
	if(pos>=11||rest<0) return 0;
	if(dp[pos][rest]!=-1) return dp[pos][rest];
	return dp[pos][rest]=func(pos,rest-coin[pos])+func(pos+1,rest);
}
int main()
{
	double nm;
	LL num;
	memset(dp,-1,sizeof dp);
	while(cin>>nm)
	{
		if(nm==0.00) break;
		num=nm*100+.005;
		//double um=ceil(nm*100.0);
		////cout<<num<<' ';
		////cout<<(int)nm*100+.005<<endl;
		//num=um;
		LL ans = func(0,num);
		printf("%6.2lf%17lld\n",nm,ans);
	}
	return 0;
}
//300.00   181490736388615
//300.00  181490736388615
//300.00  181490736388615
//300.00  181490736388615
//  0.02                0
//  0.20                4
//  2.00              293
