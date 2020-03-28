#include<stdio.h>

long long ar[10000];
long long int fibo(int a)
{
    if(a<2) return a;
    if(ar[a]!=-1) return ar[a];
    return fibo(a-1)+fibo(a-2);
}
int main()
{
    int x,i;
    while(scanf("%d",&x)==1)
    {
        if(x==0) break;

        for(i=0; i<=x; i++)
        {
            ar[i]=-1;
            ar[i]=fibo(i);
        }
        printf("%lld\n",ar[x-1]+ar[x]);
    }
    return 0;
}
