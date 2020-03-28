#include<bits/stdc++.h>
using namespace std;

int a[100],sm=0;

int main()
{

	memset(a,0,sizeof a);
	sm=0;
    for(int i=0; i<10; i++)
    {
        cin>>a[i];
        sm+=a[i];
    }
    int mn=sm;
    if(a[8]==10 && a[9]>20) mn+=10;
    
    if(a[9]>=20) a[11]=a[9]-20,a[9]=20;
    if(a[9]>=10) a[10]=a[9]-10,a[9]=10;
    sm=0;
    for(int i=0; i<10; i++)
    {
		sm+=a[i];
        if(a[i]==10)
        {
            sm+=a[i+1];
            if(a[i+1]==10)
            {
                sm+=a[i+2];
            }
        }
    }
    
    cout<<mn<<" "<<sm<<endl;
    
    return 0;
}
