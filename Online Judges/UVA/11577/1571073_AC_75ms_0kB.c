#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000];
    char tst[1000];
    int i, test,len,j,t,max,count[1000];

    for(i=0; i<26; i++)
    {
        tst[i]=i+'a';
    }

    scanf("%d",&test);
    getchar();
    for(t=0; t<test; t++)
    {
        max=0;

        gets(str);
        len=strlen(str);
        for(i=0; i<26; i++)
        {
            count[i]=0;
            for(j=0; j<len; j++)
            {
                if(str[j]>='A'&&str[j]<='Z')
                {
                    str[j]=str[j]-'A'+'a';
                }
                if(tst[i]==str[j])
                {
                    count[i]++;
                }
            }
            if(max<count[i])
            {
                max=count[i];
            }
        }

        for(i=0; i<26; i++)
        {
            if(count[i]==max)
            {
                printf("%c",tst[i]);
            }
        }
        printf("\n");
    }

    return 0;
}
