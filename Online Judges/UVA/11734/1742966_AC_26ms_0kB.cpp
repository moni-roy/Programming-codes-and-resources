#include<bits/stdc++.h>

using namespace std;

void func(char cop[])
{
    int m=0;
    char bac[10000];
    int len=strlen(cop);
    for(int k=0; k<len; k++)
    {
        if(cop[k]!=' ')
        {
            bac[m]=cop[k];
            m++;
        }
    }
    bac[m]='\0';
    strcpy(cop,bac);
    return ;
}

int main()
{
    int tst,cases=0;
    char fst[10000],snd[10000];
    cin>>tst;
    getchar();
    while(tst--)
    {
        gets(fst);
        gets(snd);
        if(strcmp(fst,snd)==0)
        {
            cout<<"Case "<<++cases<<": Yes"<<endl;
            continue;
        }
        func(fst);
        //func(snd);
        if (strcmp(fst,snd)==0) cout<<"Case "<<++cases<<": Output Format Error"<<endl;
        else cout<<"Case "<<++cases<<": Wrong Answer"<<endl;
    }
    return 0;
}
