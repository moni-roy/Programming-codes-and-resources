#include<bits/stdc++.h>

using namespace std;
int ar[1000010];
int main()
{
	int tst,cas=0;
	cin>>tst;
	while(tst--)
	{
		int num;
		cin>>num;
		for(int i=1;i<=num;i++)
		{
			cin>>ar[i];
		}
		int factor=ar[num]-ar[num-1];
		for(int i=num-2;i>=0;i--)
		{
			if(factor==ar[i+1]-ar[i]) factor++;
			factor=max(factor,ar[i+1]-ar[i]);
		}
		cout<<"Case "<<++cas<<": "<<factor<<endl;
	}
	return 0;
}
