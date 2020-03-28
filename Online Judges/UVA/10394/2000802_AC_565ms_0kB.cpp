#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<iostream>
#include<list>
#include<map>
#include<memory>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>
#include<iomanip>
#define INF (1<<28)
#define MOD 18420000
#define PB push_back
#define LL long long 
using namespace std;

bool check[90000009];
vector<LL>prime;
vector<LL>ans;

void seive()
{
	//check prime
	LL sqt=sqrt((double)MOD);
	for(LL i=3;i<=sqt;i+=2)
	{
		if(!check[i])
		{
			for(LL j=i*i;j<=MOD;j+=2*i)
			{
				check[j]=true;
			}
		}
	}
	//save prime number
	prime.PB(2);
	for(LL i=3;i<=MOD;i+=2)
	{
		if(!check[i])
		{
			prime.PB(i);
		}
	}
	//generat group prime differ 2
	for(LL i=1;i<=prime.size();i++)
	{
		if(prime[i]==(prime[i-1]+2))
		{
			ans.PB(prime[i]);
		}
	}
}
int main()
{
	seive();
	LL num;
	while(cin>>num&&num)
	{
		cout<<"("<<ans[num-1]-2<<", "<<ans[num-1]<<")"<<endl;
	}
	
	return 0;
}
//(3, 5)
