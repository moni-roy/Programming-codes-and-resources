#include<stdio.h>
#include<math.h>
long long int prime[100000],a[10000010];
 long long int prime_sieve()
{
    long long int i,j,k=0,lm,n;
    n=1000000;
    a[0]=a[1]=1;
    for(i=4; i<=n; i+=2)
        a[i]=1;
    lm=sqrt(n);
    for(i=3; i<=lm; i+=2)
    {
        if(!a[i])
        {
            for(j=i*i; j<=n; j+=i)
            {
                a[j]=1;
            }
        }

    }
    prime[k++]=2;
    for(i=3; i<=n; i+=2)
    {
        if(!a[i])
        {
            prime[k++]=i;
        }
    }
    prime[k]=1000003;
}
int main()
{
    prime_sieve();
    long long int a,b,i,counta,countb,j,la,lb;
    long long int tc,k;
    while(scanf("%d",&tc)!=EOF&&tc>0)
    {
        for(k=1; k<=tc; k++)
        {
            scanf("%lld%lld",&a,&b);
            counta=0;
            countb=0;
            if(a<=0||b<=0)
                break;
            la=sqrt(a);
            for(j=0; prime[j]<=la; j++)
            {
                counta=counta+(log10(a-.1)/log10(prime[j]))-1;

            }
            lb=sqrt(b);
            for(j=0; prime[j]<=lb; j++)
                {

                    countb=countb+log10(b+.1)/log10(prime[j])-1;

                }
            printf("%lld\n",countb-counta);

            }
    }
return 0;
}