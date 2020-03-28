#include<bits/stdc++.h>
using namespace std;
int main()
{
	string seq[6]={"BCG","BGC","CBG","CGB","GBC","GCB"};
 
	unsigned long long  bin[3][3],index,i,sum[6],min=2147483648;
 
	while(cin>>bin[0][0]>>bin[0][1]>>bin[0][2]>>bin[1][0]>>bin[1][1]>>bin[1][2]>>bin[2][0]>>bin[2][1]>>bin[2][2])
	{
		min=2147483648;
 
		sum[0]=bin[1][0]+bin[2][0] +bin[0][2]+bin[2][2] +bin[0][1]+bin[1][1];
 
		sum[1]=bin[1][0]+bin[2][0] +bin[0][1]+bin[2][1] +bin[0][2]+bin[1][2];
 
		sum[2]=bin[1][2]+bin[2][2] +bin[0][0]+bin[2][0] +bin[0][1]+bin[1][1];
 
		sum[3]=bin[1][2]+bin[2][2] +bin[0][1]+bin[2][1] +bin[0][0]+bin[1][0];
 
		sum[4]=bin[1][1]+bin[2][1] +bin[0][0]+bin[2][0] +bin[0][2]+bin[1][2];
 
		sum[5]=bin[1][1]+bin[2][1] +bin[0][2]+bin[2][2] +bin[0][0]+bin[1][0];
 
		for(i=0;i<6;i++)
		{
			if(sum[i]<min)
			{
				min=sum[i];
				index=i;
			}
 
		}
		cout<<seq[index]<<" "<<sum[index]<<endl;
 
	}
return 0;
}