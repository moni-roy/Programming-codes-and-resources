#include<stdio.h>

int main()
{
    int test,n,a,d,i,sum,sum2,j;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d%d%d",&n,&a,&d);
        if(n==1)
        {
            printf("%d\n",a);
        }
        else
        {
            sum=a;
            sum2=a;
            for(j=0; j<n-1; j++)
            {
                sum=sum+d;
                sum2=sum2+sum;
            }
            printf("%d\n",sum2);
        }

    }
    return 0;
}
