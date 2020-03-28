#include<stdio.h>

int main()
{
    long long int i,j,c,m,a,b,temp,temp_i,temp_j;

    while(scanf("%lld%lld",&i,&j)!=EOF)
    {
        temp_i=i;
        temp_j=j;
        if(i>j)
        {
            temp=i;
            i=j;
            j=temp;
        }
        m=0;
        for(a=i; a<=j; a++)
        {
            c=1;
            b=a;
            while(b!=1)
            {
                if(b%2==1) b=(3*b)+1;
                else b=b/2;
                c++;

            }
            if(c>m)
            {
                m=c;
            }
        }
        printf("%lld %lld %lld\n",temp_i,temp_j,m);
    }

    return 0;
}
