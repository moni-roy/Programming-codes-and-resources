#include <bits/stdc++.h>
using namespace std;
#define I(a) scanf("%d",&a)

int a,ar[100010],Ans;

int main()
{
    while(I(a)==1)
    {
        if(a==0) break;
        int k=0;
        ar[k++]=a;
        while(I(a)==1)
        {
            if(a==0) break;
            ar[k++]=a;
        }
        Ans=0;

        for(int i=0; i<k; i++)
        {
            for(int j=0; j<k; j++)
            {
                if((ar[i]-ar[j])!=0) Ans=__gcd(Ans,abs(ar[i]-ar[j]));
            }
        }
        cout<<Ans<<endl;
    }
    return 0;
}
