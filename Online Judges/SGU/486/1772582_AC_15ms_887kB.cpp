#include<bits/stdc++.h>
using namespace std;
int main()
{
	int cow,bull;
	char fst[10],snd[10];
	
	while(scanf("%s %s",fst,snd)==2)
	{
		bull=0;
		cow=0;
		for(int i=0;i<4;i++)
		{
			if(fst[i]==snd[i])
			{
				bull++;
			}
			for(int j=0;j<4;j++)
			{
				if(fst[i]==snd[j]&&i!=j)
				{
					cow++;
				}
			}
		}
		cout<<bull<<" "<<cow<<endl;
	}
	return 0;
}
