#include<stdio.h>


int main()
{
    long long num,a[10009],pric,i,j,min,min2,dif,num1,num2,num3,num4;

    while(scanf("%lld",&num)!=EOF)
    {
        min2=100000001;
        for(i=0; i<num; i++)
        {
            scanf("%lld",&a[i]);
        }
        scanf("%lld",&pric);

        for(i=0; i<num-1; i++)
        {
            for(j=i+1; j<num; j++)
            {
                dif=a[i]+a[j];
                if(dif==pric)
                {
                    if(a[i]>a[j])
                    {
                        num1=a[j];
                        num2=a[i];
                    }
                    else
                    {
                        num1=a[i];
                        num2=a[j];
                    }
                    min=num2-num1;
                    if(min<min2)
                    {
                        min2=min;
                        num4=num2;
                        num3=num1;
                    }
                }

			}
        }
        printf("Peter should buy books whose prices are %lld and %lld.\n\n",num3,num4);
    }
    return 0;
}
