#include <bits/stdc++.h>

using namespace std;
char fibonaci[5004][10000];
char cop[10000],copp[10000],str[10000];
void reverse(char nm[])
{
	int len=strlen(nm);
	for(int i=0,x=len-1;i<x;x--,i++)
	{
		int ch=nm[x];
		nm[x]=nm[i];
		nm[i]=ch;
	}
	return ;
}
void FIBBO()
{
	strcpy(fibonaci[0],"0");
	strcpy(fibonaci[1],"1");
	strcpy(fibonaci[2],"1");
	strcpy(fibonaci[3],"2");
	for(int i=3;i<5002;i++)
	{
		int len2,len1,len;
	
		int j,sum=0,rem=0;
		strcpy(cop,fibonaci[i-1]);
		strcpy(copp,fibonaci[i-2]);
		reverse(cop);
		reverse(copp);
		len1=strlen(cop);
		len2=strlen(copp);
		len=max(len1,len2);
		for( j=0;j<len;j++)
		{
			if(j>=len1) cop[j]='0';
			if(j>=len2) copp[j]='0';
			sum=rem+(cop[j]-'0')+(copp[j]-'0');
			str[j]=(sum%10)+'0';
			rem=sum/10;
		}
		if(rem>0)
		{
			str[j]='1';
			j++;
		}
		str[j]='\0';
		reverse(str);
		strcpy(fibonaci[i],str);
	}
}

int main()
{
	FIBBO();
	int num;
	while(cin>>num)
	{
		cout<<"The Fibonacci number for "<<num<<" is ";
		puts(fibonaci[num]);
	}
	return 0;
}
