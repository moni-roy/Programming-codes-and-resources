#include<bits/stdc++.h>

using namespace std;

int main()
{
    int len,len2,max=0;
    string word,ans,comp;

    while(cin>>word&&word!="E-N-D")
    {
        len=word.size();
//        int j=0;
//        for(int i=0;i<len;i++)
//        {
//            if(isalpha(word[i])&&word[i]=='-')
//            {
//                comp[j]=word[i];
//                j++;
//            }
//        }
//        comp[j]='\0';
//        len2=comp.size();
        if(max<len)
        {
            max=len;
            ans=word;
        }
        //cout<<comp<<endl;
    }
    for(int i=0;i<ans.size();i++)
    {
        ans[i]=tolower(ans[i]);
        if(ans[i]=='-'||isalpha(ans[i]))
        {
            cout<<ans[i];
        }
    }
    cout<<endl;

    return 0;
}
