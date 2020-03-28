#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ts,vs[30];
    string s;
    cin>>ts;
    getchar();
    while(ts--)
    {
        getline(cin,s);
        int l = s.size();
        memset(vs,0,sizeof vs);
        for(int i=0; i<l; i++)
        {
            if(isalpha(s[i]))
            {
                s[i]= tolower(s[i]);
                vs[s[i]-'a']=1;
            }
        }
        int f = 0;
        char Ans ;
        for(int i=0; i<26; i++)
        {
            if(vs[i]==0)
            {
                f=1;
                Ans = (char)(i+'a');
                break;
            }
        }
        if(f) cout<<Ans<<endl;
        else cout<<"~"<<endl;
    }
    return 0;
}
