#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i=0,sum1=0,sum2=0,flag=1;
	char ch[60];
	int num;
	cin>>num;
	while(i<num)
	{
		cin>>ch[i];
		i++;
	}
	ch[i]='\0';
	//puts(ch);
	for(int j=0;j<strlen(ch);j++)
	{
		int mk=ch[j]-'0';
		if(mk!=4&&mk!=7)
		{
			flag=0;
			break;
		}
		if(num/2>j)
		{
			sum1+=mk;
		}
		else sum2+=mk;
		//cout<<sum1;
		
	}
	//cout<<sum1<<' '<<sum2<<endl;
	if(flag==1&&sum1==sum2) puts("YES");
	else puts("NO");
	//main();
	return 0;
}
