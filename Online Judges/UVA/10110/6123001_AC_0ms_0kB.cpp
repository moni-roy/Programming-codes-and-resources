#include<stdio.h>
#include<math.h>
int main()
{
    long long int n,a;
    while(scanf("%lld",&n)&&n!=0)
    {
            a=(long long)sqrt(n);
    if(a*a==n)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    }

    return 0;

}