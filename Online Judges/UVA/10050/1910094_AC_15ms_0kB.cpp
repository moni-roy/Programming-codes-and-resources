#include<bits/stdc++.h>
#define LL long long int

using namespace std;

int main()
{
	int k,d,ndm,test;
	cin>>test;
	while(test--)
	{
		cin>>d>>k;
		int num[100000];
		for(int i=0;i<k;i++) cin>>num[i];
		ndm=0;
		for(int i=1;i<=d;i++)
		{
			for(int j=0;j<k;j++)
			{
				if(i%num[j]==0&&i%7!=0&&(i+1)%7!=0) 
				{
					ndm++;
					break;
				}
		          }
		
                  }	
         	//LL damage=d-ndm;
		cout<<ndm<<endl;
	}
	return 0;
}
