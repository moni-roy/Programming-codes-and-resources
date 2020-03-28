#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cs=0;
    double l,w,th,r,rt;
    while(scanf("%lf : %lf",&l,&w)==2)
    {
        th=atan(w/l);
        r=sqrt(l*l+w*w)/2;
        rt=400.0/(2*l+2*r*2*th);
        printf("Case %d: %.10lf %.10lf\n",++cs,rt*l,rt*w);
    }
}
