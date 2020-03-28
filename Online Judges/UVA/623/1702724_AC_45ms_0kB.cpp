#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

char str[10000][10000],sm[10000]={0};

void reverses(char give[])
{
    long long int x,len,y,ch;
    len=strlen(give);
    for(x=0,y=len-1; x<y; x++,y--)
    {
        ch=give[x];
        give[x]=give[y];
        give[y]=ch;
    }
    return ;
}
void string_mlp(char mlp[],long long int nm)
{
    long long int len1,carry=0,k;
    long long int  sum;
    reverses(mlp);
    len1=strlen(mlp);
    for(k=0; k<len1; k++)
    {
        sum=((mlp[k]-'0')*nm)+carry;
        carry=sum/10;
        sm[k]=(sum%10)+'0';
    }
    m:;
    if(carry<10&&carry>0)
    {

        sm[k]=(carry%10)+'0';
    }
    if(carry>9)
    {
    sm[k]=carry%10+'0';
    carry=carry/10;
    k++;
    goto m;
    }
    reverses(sm);
    strcpy(str[nm],sm);
    return ;
}

int main()
{
    long long num,i,used[10000]= {0};
    char cop[10000];
    char d[]= {'1','\0'},c[]={'1','\0'};
    strcpy(str[1],d);
    strcpy(str[0],c);
        used[0]=2;
        used[1]=2;
    while(cin>>num)
    {
        if(strlen(str[num])>0)
        {
            goto skip;
        }
        else
        {
        for(i=2; i<=num; i++)
        {
            if(!used[i])
            {
                strcpy(cop,str[i-1]);
                string_mlp(cop,i);
            }
            used[i]=2;
        }
        }
        skip:;
        printf("%lld!\n%s\n",num,str[num]);
    }
    return 0;
}
