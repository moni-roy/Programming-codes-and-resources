/* URDHAB HALDER
   JU, SAVAR, BD */

#include<stdio.h>
int main()
{
    long long int t,T,N,i;
    scanf("%lld",&T);

    for(t=1;t<=T;t++)
    {
        scanf("%lld",&N);
        long long int s=0,j;
        i=N;
        while(i>0)
        {
            j=i%10;
            s=s+(j*j);
        if(i/10<1 && s>9)
            {
                i=s;
                s=0;

            }
                else
                    i=i/10;
        }
            if(s==1)
                printf("Case #%lld: %lld is a Happy number.\n",t,N);
            else
                printf("Case #%lld: %lld is an Unhappy number.\n",t,N);
    }

    return 0;
}
