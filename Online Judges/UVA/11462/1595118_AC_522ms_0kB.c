#include<stdio.h>

int main()
{
    long long int age, i,count[1000],num,c,j;
    while(scanf("%lld",&num)==1&&num)
    {
        for(i=0; i<150; i++)
        {
            count[i]=0;
        }
        for(i=0; i<num; i++)
        {
            scanf("%lld",&age);
            count[age]++;
        }
        c=0;
        for(i=1; i<150; i++)
        {
            for(j=1; j<=count[i]; j++)
            {
                printf("%lld",i);
                c++;
                if(c<num)
                    printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
