#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define dl double

///int func(dl x, dl y)
///{
///	for(int i=0;i<n;i++)
///	{
///		if(ar[i][0]=='1')
///		{
///			if((x>ar[i][1]&&x<ar[i][3])&&(y>ar[i][4]&&y<ar[i][2]))
///			{
///				return i;
///			}
///		}
///		else
///		{
///			if(((x-ar[i][1])*(x-ar[i][1]))+((y-ar[i][2])*(y-ar[i][2]))<=(ar[i][3]*ar[i][3]))
///			{
///				return i;
///			}
///		}
///	}
///	return -1;
///}
int main()
{
	char ch;
	dl ar[100][100];
	int n=0;	
	dl x,y,a,b;
	while(cin>>ch&&ch!='*')
	{
		if(ch=='r')
		{
			cin>>x>>y>>a>>b;
			ar[n][0]=1;
			ar[n][1]=x;
			ar[n][2]=y;
			ar[n][3]=a;
			ar[n][4]=b;
		}
		else
		{
			cin>>x>>y>>a;
			ar[n][0]=2;
			ar[n][1]=x;
			ar[n][2]=y;
			ar[n][3]=a;
		}
		n++;
	}
	dl p,q;
	int cnt=1;
	while(cin>>p>>q&&p!=9999.9 &&q!=9999.9)
	{
		int flg=0;
		
		for(int i=0;i<n;i++)
		{
			if(ar[i][0]==1)
			{
				if((p>ar[i][1]&&p<ar[i][3])&&(q>ar[i][4]&&q<ar[i][2]))
				{
					cout<<"Point "<<cnt<<" is contained in figure "<<i+1<<endl;
					flg=1;
				}
			}
			else
			{
				if(((p-ar[i][1])*(p-ar[i][1]))+((q-ar[i][2])*(q-ar[i][2]))<=(ar[i][3]*ar[i][3]))
				{
					cout<<"Point "<<cnt<<" is contained in figure "<<i+1<<endl;
					flg=1;
				}
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
