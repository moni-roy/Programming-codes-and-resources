#include <bits/stdc++.h>
using namespace std;
string st="aAeEoOyYuUiI";
bool vowel(char a)
{
    for(int i=0;i<12;i++)
    {
        if(a==st[i]) return true;
    }
    return false;
}
int main()
{
    string ss,cs;
    cin>>ss;
    for(int i=0;i<(int)ss.size();i++)
    {
        if(vowel(ss[i])==0) cs+=ss[i];
    }

    for(int i=0;i<(int)cs.size();i++)
    {
        cout<<".";
        if(cs[i]>='A'&&cs[i]<='Z')
        {
            cout<<(char)(cs[i]-'A'+'a');
        }
        else cout<<cs[i];
    }
    return 0;
}
