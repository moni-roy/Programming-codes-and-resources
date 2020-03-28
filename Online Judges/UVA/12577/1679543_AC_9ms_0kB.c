#include<stdio.h>

int main()
{
    char str[100];
    int cas=1;

    while(NULL!=gets(str))
    {
        if(strcmp(str,"*")==0) break;
        else if(strcmp(str,"Hajj")==0) printf("Case %d: Hajj-e-Akbar\n",cas);
        else if(strcmp(str,"Umrah")==0) printf("Case %d: Hajj-e-Asghar\n",cas);
        cas++;
    }
    return 0;
}
