#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define dl double

int main()
{
	char ch;
	dl ar[100][100];
	int n=0;	
	dl x,y,a,b;
	while(cin>>ch&&ch!='*')
	{
		cin>>x>>y>>a>>b;
		ar[n][1]=x;
		ar[n][2]=y;
		ar[n][3]=a;
		ar[n][4]=b;
		n++;
	}
	dl p,q;
	int cnt=1;
	while(cin>>p>>q&&p!=9999.9 &&q!=9999.9)
	{
		int flg=0;
		
		for(int i=0;i<n;i++)
		{
			if((p>ar[i][1]&&p<ar[i][3])&&(q>ar[i][4]&&q<ar[i][2]))
			{
				cout<<"Point "<<cnt<<" is contained in figure "<<i+1<<endl;
				flg=1;
			}
		}
		if(flg==0)
		{
			cout<<"Point "<<cnt<<" is not contained in any figure"<<endl;
		}
		cnt++;
	}
	return 0;
}

