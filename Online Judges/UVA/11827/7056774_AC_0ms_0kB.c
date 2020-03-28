#include<stdio.h>
#include<math.h>
#include<string.h>
int gcd(int a,int b)
{
    if(b==0)
        return a;
    gcd(b,a%b);
}
int main()
{
    int n,tc,m,i,j,a[1000],k,max,c;
    char s[100000];
    gets(s);
    tc=0;
    m=strlen(s);
    for(i=0;i<m;i++)
        tc=tc*10+(s[i]-'0');
    for(i=1;i<=tc;i++)
    {
        gets(s);
        m=strlen(s);
        c=0;
        max=0;
        n=0;
        for(j=0;j<m;j++)
            {
                if(s[j]==' ' && n!=0)
                {
                    a[c++]=n;
                    n=0;
                }
                else
                    n=n*10+(s[j]-'0');
            }
            if(n!=0) a[c++]=n;
        for(j=0;j<c;j++)
            for(k=j+1;k<c;k++)
        {
            n=gcd(a[j],a[k]);
            if(n>max)
                max=n;
        }
        printf("%d\n",max);
        max=0;
    }
    return 0;
}