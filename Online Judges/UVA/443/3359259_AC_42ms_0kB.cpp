#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define md 2000000000
ll sv[500001];
map<ll,ll>m;
ll pos=2;
void humble(ll tm)
{
	if(pos>5842||tm>2000000000ll) return;
	
	if(m.find(tm*2)==m.end()&&tm*2<=md){
		 m[tm*2]=1;
		 sv[pos++]=tm*2;
		 humble(tm*2);
	 }
	if(m.find(tm*3)==m.end()&&tm*3<=md){
		m[tm*3]=1;
		sv[pos++]=tm*3;
		humble(tm*3);
	 }
	if(m.find(tm*5)==m.end()&&tm*5<=md){
		m[tm*5]=1;
		sv[pos++]=tm*5;
		humble(tm*5);
	 }
	if(m.find(tm*7)==m.end()&&tm*7<=md) {
		m[tm*7]=1;
		sv[pos++]=tm*7;
		humble(tm*7);
	 }
}

int main()
{
	sv[1]=1;
	humble(1);
	sort(sv,sv+pos);
	ll n,ck;
	string ss="";
	while(cin>>n&&n)
	{
		ck=0;
		ss="th";
		if(n>=4&&n<=20) ck=1;
		if(n==1||n%10==1) ss="st";
		if(n==2||n%10==2) ss="nd";
		if(n==3||n%10==3) ss="rd";
		if((n/10)%10==1) ss="th";
		
		cout<<"The "<<n<<ss<<" humble number is "<<sv[n]<<"."<<endl;
	}
	return 0;
}
