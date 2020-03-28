#include<stdio.h>
#include<string.h>

char num[9999][10000];
char sm[10000];

void reverse(char give[])
{
    long long int x,len,y;
    char ch;
    len=strlen(give);
    for(x=0,y=len-1; x<y; x++,y--)
    {
        ch=give[x];
        give[x]=give[y];
        give[y]=ch;
    }
    return ;
}

void string_add(char add[],char revese[],long long int nm)
{
    long long int len1,len2,carry=0,i,max;
    long long int  sum;
    len1=strlen(add);
    len2=strlen(revese);
    reverse(add);
    reverse(revese);
    if(len1>len2)
    {
        max=len1;
    }
    else
    {
        max=len2;
    }
    for(i=0; i<max; i++)
    {
        if(i>=len1)
        {
            add[i]='0';
        }
        if(i>=len2)
        {
            revese[i]='0';
        }
        sum=(add[i]-'0')+(revese[i]-'0')+carry;
        carry=sum/10;
        sm[i]=(sum%10)+'0';
    }
    if(carry>0)
    {
        sum=1;
        sm[i]=1+'0';
    }
    reverse(sm);
    strcpy(num[nm],sm);
    return ;
}
int main()
{
    long long int m,n,use[10000]= {0};
    char d[]= {'0','\0'};
    char d1[]= {'1','\0'};
    char d2[]= {'1','\0'};
    char A[10000],B[10000];

   while(scanf("%lld",&m)!=EOF)
    {
        strcpy(num[0],d);
        strcpy(num[1],d1);
        strcpy(num[2],d2);

        use[0]=2;
        use[1]=2;
        use[2]=2;

        if(m==0)
        {
            printf("The Fibonacci number for %lld is 0\n",m);
        }
        if(m==1)
        {
            printf("The Fibonacci number for %lld is 1\n",m);
        }
        if(m==2)
        {
            printf("The Fibonacci number for %lld is 1\n",m);
        }

        else if(m>2)
        {
            if(strlen(num[m])>0)
            {
                goto skip;
            }
            for(n=2; n<=m; n++)
            {
                if(!use[n])
                {
                    strcpy(A,num[n-1]);
                    strcpy(B,num[n-2]);

                    string_add(A,B,n);
                }
                use[n]=2;
            }
            skip:;
            printf("The Fibonacci number for %lld is %s\n",m,num[m]);
        }
    }

    return 0;
}
