#include<stdio.h>
#include<math.h>

int main()
{
    float a,u,v,t,s;
    int j=0,i;

    while(scanf("%d",&i)==1)
    {
        j++;
        if(i==1)
        {
            scanf("%f%f%f",&u,&v,&t);
            s=((u+v)/2.0)*t;
            a=(v-u)/t;
            printf("Case %d: %.3f %.3f\n",j,s,a);
        }
        if(i==2)
        {
            scanf("%f%f%f",&u,&v,&a);
            s=((v*v)-(u*u))/(2*a);
            t=(v-u)/a;
            printf("Case %d: %.3f %.3f\n",j,s,t);
        }
        if(i==3)
        {
            scanf("%f%f%f",&u,&a,&s);
            v=sqrt(u*u+2*a*s);
            t=2*s/(u+v);
            printf("Case %d: %.3f %.3f\n",j,v,t);
        }
        if(i==4)
        {
            scanf("%f%f%f",&v,&a,&s);
            u=sqrt(v*v-2*a*s);
            t=2*s/(u+v);
            printf("Case %d: %.3f %.3f\n",j,u,t);
        }
        if(i==0) break;
    }
    return 0;
}
