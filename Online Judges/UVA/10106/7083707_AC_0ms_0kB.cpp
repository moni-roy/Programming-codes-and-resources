#include<stdio.h>
#include<math.h>
#include<string.h>
int product[1000009];
int main()
{
    char first[555],second[555];
    int i,j,k,cnt;
    while(scanf("%s %s",first,second)==2)
    {
        cnt=0;
        int lf=strlen(first);
        int ls=strlen(second);
        for(i=lf-1;i>=0;i--)
        {
            k=cnt;
            cnt++;
            for(j=ls-1;j>=0;j--)
            {
                product[k]+=(second[j]-'0')*(first[i]-'0');
                product[k+1]+=product[k]/10;
                product[k]%=10;
                k++;
            }
        }
        int flag=0;
        k++;
        while(!product[k])k--;
           for(;k>=0;k--)
            {
                printf("%d",product[k]);
                product[k]=0;
                flag=1;
            }
            if(!flag)
                printf("0");
        printf("\n");

    }
    return 0;
}

