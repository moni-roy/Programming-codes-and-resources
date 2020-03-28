#include<bits/stdc++.h>
using namespace std;
int main()
{
	string num;
	long long tst,siz;
	cin>>tst;
	//getchar();
	while(tst--)
	{
		cin>>num;
		siz=num.size();
		if(num=="1"||num=="4"||num=="78") cout<<"+"<<endl;
		else if(num[siz-1]=='5'&&num[siz-2]=='3') cout<<"-"<<endl;
		else if(num[0]=='1'&&num[1]=='9'&& num[2]=='0') cout<<"?"<<endl;
		else cout<<"*"<<endl;
	}
	return 0;
}
