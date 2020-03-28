/*sayem*/

#include<stdio.h>
int main()
{
    int t,f,a,b,d,c,i,j,sum;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        sum=0;
        scanf("%d",&f);
        for(j=1;j<=f;j++)
        {
            scanf("%d%d%d",&a,&b,&c);
            d=a*c;
            sum=sum+d;
        }
        printf("%d\n",sum);
    }
    return 0;
}
