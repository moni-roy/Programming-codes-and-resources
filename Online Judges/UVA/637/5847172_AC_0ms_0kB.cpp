#include<stdio.h>

int main()
{
    int p,a,b,c,d,k;
    while(scanf("%d",&p)&&p!=0&&p>0)
    {
        printf("Printing order for %d pages:\n",p);
        if(p==1)
        {
            printf("Sheet 1, front: Blank, 1\n");
        }
        else
        {
            a=p/4;
            b=p%4;
            if(b!=0)
            {
                a=a+1;
            }
            c=1;
            d=a*4;
            for(k=1; k<=a; k++)
            {

                if(d<=p)
                {
                    printf("Sheet %d, front: %d, %d\n",k,d,c);
                }
                else
                {
                    printf("Sheet %d, front: Blank, %d\n",k,c);
                }
                c++;
                d--;
                if(d<=p)
                {
                    printf("Sheet %d, back : %d, %d\n",k,c,d);
                }
                else
                {
                    printf("Sheet %d, back : %d, Blank\n",k,c,d);
                }
                c++;
                d--;

            }
        }
    }
    return 0;
}