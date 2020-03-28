#include <bits/stdc++.h>
using namespace std;
int sv[222][222];
string s;
int go(int x,int y){
	int &ret = sv[x][y];
	if(ret!=-1) return ret;
	if(x==y) return 2;
	ret = 1e8;
	if(s[x]==s[y]) ret = min(ret,go(x,y-1));
	for(int i = x;i<y;i++){
		ret = min(ret,go(x,i)+go(i+1,y));
	}
	return ret;
}

int main()
{
	int ts;
	cin>>ts;
	getchar();
	while(ts--)
	{
		getline(cin,s);
		memset(sv,-1,sizeof sv);
		int Ans = go(0,s.size()-1);
		cout<<Ans+s.size()<<endl;
	}
	return 0;
}
