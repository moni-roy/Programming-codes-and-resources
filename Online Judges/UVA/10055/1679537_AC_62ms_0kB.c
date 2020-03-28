#include<stdio.h>

int main()
{
    long long int a,b,c,d;

    while(scanf("%lld%lld",&a,&b)==2)
    {
        if(a<=b)
        {
            c=-1*(a-b);
            printf("%lld\n",c);
        }
        else
        {
            d=a-b;
            printf("%lld\n",d);
        }
    }
    return 0;
}
