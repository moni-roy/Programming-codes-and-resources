#include<stdio.h>

int main()
{
    int i,a[5],T,n,m,temp;

    scanf("%d",&T);
    for(i=1; i<=T; i++)
    {
        scanf("%d%d%d",&a[0],&a[1],&a[2]);
        for(m=0;m<2;m++)
		{
			for(n=m+1;n<3;n++)
			{
				if(a[m]>a[n])
				{
					temp=a[m];
					a[m]=a[n];
					a[n]=temp;
				}
			}
		}

        printf("Case %d: %d\n",i,a[1]);
    }
    return 0;
}
