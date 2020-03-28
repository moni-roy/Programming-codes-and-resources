#include<stdio.h>

int main()
{
    int i,T,a,b,j,s;

    scanf("%d",&T);
    for(i=1; i<=T; i++)
    {
        s=0;
        scanf("%d%d",&a,&b);
        for(j=a; j<=b; j++)
        {
            if(j%2==1)
            {
                s=s+j;
            }
        }
        printf("Case %d: %d\n",i,s);
    }
    return 0;
}
