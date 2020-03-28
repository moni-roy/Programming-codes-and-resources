#include<stdio.h>

int main()
{
    long long int num,arr[30005],bar[30005],j,i,count,temp;
    while(scanf("%lld",&num)==1)
    {
        for(i=0; i<num; i++)
        {
            scanf("%lld",&arr[i]);
        }
        for(j=0; j<num-1; j++)
        {
            bar[j]=arr[j+1]-arr[j];
            if(bar[j]<0)
            {
                bar[j]=bar[j]*(-1);
            }
        }
        for(i=0; i<num-2; i++)
        {
            for(j=i+1;j<num-1;j++)
            {
            if(bar[i]>bar[j])
            {
                temp=bar[i];
                bar[i]=bar[j];
                bar[j]=temp;
            }
        }
        }
        count=0;
        for(i=0;i<num-1;i++)
        {
            if(bar[i]!=i+1)
            {
				printf("Not jolly\n");
                count=1;
                break;
            }
        }
        if(count!=1) { 
        printf("Jolly\n");}
    }

    return 0;
}
