#include<stdio.h>

int main()
{
    long long int m,k;

    while(scanf("%lld",&m)!=EOF)
    {
        if(m<0) break;
        else
        {
            k=m*(m+1)/2+1;
        }
        printf("%lld\n",k);
    }
    return 0;
}
