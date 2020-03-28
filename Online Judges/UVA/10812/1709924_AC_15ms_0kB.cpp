#include<stdio.h>

int main()
{
    long long t,T,s,d,x,y;
    scanf("%lld",&T);
    for(t=0; t<T; t++)
    {
        scanf("%lld%lld",&s,&d);

        x=(s+d)/2;
        y=(s-d)/2;

        if(x+y==s&&s>=d)
        {
            printf("%lld %lld\n",x,y);
        }
        else printf("impossible\n");

    }
    return 0;
}
