#include<cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    long long int t,s,h,i,j,k,m,temp,a1[20050],min,dif;
    scanf("%lld",&t);
    for(i=0; i<t; i++)
    {
        scanf("%lld%lld",&s,&m);
        min=999999999;
        for(j=0; j<s; j++)scanf("%lld",&a1[j]);
        if(m==1)
        {
            printf("0\n");
        }
        else
        {
            sort(a1,a1+s);
            for(j=s-1;j>=m-1;j--)
            {
            dif=a1[j]-a1[j-m+1];
            if(dif<min)
            {
            min=dif;
            }
            }
            printf("%lld\n",min);
        }
    }
    return 0;
}
