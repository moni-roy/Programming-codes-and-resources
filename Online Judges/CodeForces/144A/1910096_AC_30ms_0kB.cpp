#include<bits/stdc++.h>

using namespace std;

int main()
{
	int num,ar[1000],i,min=1110,max=0,mnpo,mxpo;
	cin>>num;
	for(i=0;i<num;i++)
	{
		cin>>ar[i];
		if(min>=ar[i])
		{
			min=ar[i];
			mnpo=i;
		}
		if(max<ar[i])
		{
			max=ar[i];
			mxpo=i;
		}
	}
	int ans=num-mnpo-1+mxpo;
	if(mxpo>mnpo) ans=ans-1;
	cout<<ans<<endl;
	
	return 0;
}
