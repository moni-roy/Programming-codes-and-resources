#include <bits/stdc++.h>

using namespace std;
string fibonaci[5005];

string rever(string nm)
{
	int len =nm.length();
	int ch;
	
	for(int i=0,x=len-1;i<x;x--,i++)
	{
		ch=nm[i];
		nm[i]=nm[x];
		nm[x]=ch;
	}
	return nm;
}

void FIBBO()
{
	string cop,copp,str;
	
	fibonaci[0]="0";
	fibonaci[1]="1";
	fibonaci[2]="1";
	
	int len1,len2,i;
	
	for( i=3;i<5005;i++)
	{
		//cout<<9<<endl;
		//len1=fibonaci[i-1].size();
		//len2=fibonaci[i-2].size();
		
		cop=fibonaci[i-1];
		copp=fibonaci[i-2];
		
		cop=rever(cop);		
		copp=rever(copp);
		
		len1=cop.size();
		len2=copp.size();
		
		int len=max(len1,len2);
		int sum=0,rem=0;
		
		for(int j=0;j<len;j++)
		{
			if(j>=len1)
			{
				cop[j]='0';
			}
			if(j>=len2)
			{
				copp[j]='0';
			}
			sum=rem+(cop[j]-'0')+(copp[j]-'0');
			str+=((sum)%10)+'0';
			
			rem=sum/10;
		}
		if(rem>0)
		{
			str+='1';

		}
		
		fibonaci[i]=rever(str);
		str.clear();
	}
	return ;
}

int main()
{
	int num;
	FIBBO();
	//freopen("out2.txt","w",stdout);
	while(cin>>num)
	{
		cout<<"The Fibonacci number for "<<num<<" is "<<fibonaci[num]<<endl;
		
	}
	return 0;
}
