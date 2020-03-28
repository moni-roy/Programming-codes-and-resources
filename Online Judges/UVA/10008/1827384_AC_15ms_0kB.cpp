#include<bits/stdc++.h>
using namespace std;
int tst,check[100],i,j;
	char num[1000];
int main()
{
	cin>>tst;
	getchar();
	int max=0;
	while(tst--)
	{
		gets(num);
		for(i=0;i<strlen(num);i++)
		{
			if(num[i]>='a'&& num[i]<='z')
			{
				num[i]=num[i]-'a'+'A';
			}
			if(num[i]>='A' && num[i]<='Z')
			{
				check[num[i]]++;
			if(max<check[num[i]])
			{
				max=check[num[i]];
			}
			}
		}
	}
	for(i=max;i>=1;i--)
	{
		for(j='A';j<='Z';j++)
		{
			if(i==check[j])
			{
				printf("%c %d\n",j,i);
			}
		}
	}
	return 0;
}
		
