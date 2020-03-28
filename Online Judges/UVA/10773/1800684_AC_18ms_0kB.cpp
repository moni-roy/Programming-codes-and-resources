//somu
#include<stdio.h>
#include<math.h>
int main()
{
    int i,t;
    double t1, d, v, u;
scanf("%d",&t);
        for(i=1; i<=t; i++)
        {
            scanf("%lf %lf %lf",&d,&v,&u);
            if(v>=u || v<=0 || u<=0) printf("Case %d: can't determine\n",i);
            else
            {
                t1=d/sqrt(u*u-v*v)-d/u;
                printf("Case %d: %.3lf\n",i,t1);
            }
        }
    return 0;
}