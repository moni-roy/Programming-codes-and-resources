#include<stdio.h>

int main()
{
    int h,m;
    float ans;
    while(scanf("%d:%d",&h,&m)!=EOF)
    {
        if(h==0&&m==0) break;
        ans=((11.0*m)/2.0)-(30.0*h);
        if(ans<0)
        {
            ans=-1*ans;
        }
        if(ans>180)
        {
            ans=360.0-ans;
        }
        printf("%.3f\n",ans);
    }
    return 0;
}
