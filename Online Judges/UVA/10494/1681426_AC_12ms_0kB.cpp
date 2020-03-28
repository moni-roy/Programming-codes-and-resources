#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
    char ch ,nm[100000];
    long long mn,i,mod,ans,ans2[100000];
    while(scanf("%s %c %lld",nm,&ch,&mn)!=EOF)
    {
        long long mk,len=strlen(nm);
        mod=0;
        for(i=0; i<len; i++)
        {
            ans=((mod*10)+(nm[i]-'0'));
            ans2[i]=((mod*10)+(nm[i]-'0'))/mn;
            mod=ans%mn;
        }
        long long k=0,flag=0;
        if(ch=='/')
        {
            while(ans2[k]==0) k++;
            for(mk=k; mk<i; mk++)
            {
                printf("%lld",ans2[mk]);
                flag=1;
            }
            if(!flag)
            {
            cout<<"0";
            }

            printf("\n");
        }

        else
        {
            cout<<mod<<endl;
        }
    }
    return 0;
}
