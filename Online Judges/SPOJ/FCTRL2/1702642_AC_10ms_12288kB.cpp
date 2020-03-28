#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

char str[1000][10000],sm[10000];

void reverses(char give[])
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

    if(carry>0)
    {
    m:;
        sm[k]=carry%10+'0';
        carry=carry/10;
    }
    if(carry>0)
    {
    k++;
    goto m;
    }
    reverses(sm);
    strcpy(str[nm],sm);
    return ;
}

int main()
{
    long long tst,num,cases=0,i,j,used[1000]= {0};
    char cop[1000];
    char d[]= {'1','\0'},E[]={'2','\0'};;
    cin>>tst;
    while(tst--)
    {
        cin>>num;
        strcpy(str[1],d);
        strcpy(str[2],E);
        used[0]=1;
        used[1]=1;
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
        printf("%s\n",str[num]);
    }
    return 0;
}
