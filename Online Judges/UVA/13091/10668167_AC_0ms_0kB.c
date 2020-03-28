#include<stdio.h>

int main()
{
    int t,i,j,k,flag,l,x;
    char ch;
    scanf("%d",&t);
    getchar();
    for(i=1; i<=t; i++)
    {
        flag=0;

        for(j=1; j<=5; j++)
        {
            l=0;
            for(k=1; k<=5; k++)
            {
                scanf("%c",&ch);
                if(ch=='|')
                {
                    l=1;
                    continue;
                }
                if((l==1&&ch=='>')||(l==0&&ch=='<'))
                {
                    flag=1;
                }
                else if((l==1&&ch=='<')||(l==0&&ch=='>')){
                    flag=0;
                }

            }
            getchar();
        }

        if(flag==1)
            printf("Case %d: No Ball\n",i);
        else
            printf("Case %d: Thik Ball\n",i);
            getchar();

    }

    return 0;
}