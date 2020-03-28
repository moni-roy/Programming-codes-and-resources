/*sayem*/

#include<stdio.h>
int main()
{
   long long int n,r;
    while(scanf("%lld",&n)==1)
    {
        if(n==0)
        {
            break;
        }
        if(n>=101)
        {
            r=n-10;
        }
        if(n<=100)
        {
            r=91;
        }
        printf("f91(%lld) = %lld\n",n,r);

    }
    return 0;
}
