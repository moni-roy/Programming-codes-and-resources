#include<stdio.h>
int main()
{
    long long int n,i,c,a,b,x,y,j,max=0;
    while(scanf("%lld %lld",&a,&b)==2)
    {
        x=a;
        y=b;
        if(a>b)
        {
            c=a;
            a=b;
            b=c;
        }
        max=0;
        for(j=a; j<=b; j++)
        {
            n=j;
            for(i=1; ; i++)
            {
                if(n==1)
                {
                    break;
                }
                if(n%2==0) n=n/2;
                else if(n%2!=0) n=(3*n)+1;
            }
            if(max<i) max=i;
        }
        printf("%lld %lld %lld\n",x,y,max);
    }
    return 0;
}
