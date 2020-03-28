#include<stdio.h>

int main()
{
    int num,n,l,m,s,f;
    while(scanf("%d",&num)==1)
    {
    n=1;
        while(n!=0)
        {
            num=num+1;
            l=num%10;
            m=(num/10)%10;
            s=((num/10)/10)%10;
            f=(((num/10)/10)/10)%10;
            if(l==m||l==s||l==f)
            {
                n=1;
            }
            else if(m==l||m==s||m==f)
            {
                n=1;
            }
            else if(s==m||s==l||s==f)
            {
                n=1;
            }
            else n=0;
        }
        printf("%d\n",num);
    }
    return 0;
}
