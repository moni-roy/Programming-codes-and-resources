#include <bits/stdc++.h>
using namespace std;
int k,ans;
string s,d;
struct trie
{
    trie *lnk[27];
    trie()
    {
        for(int i=0; i<27; i++) lnk[i]=NULL;
    }
}*root;

int trie_insert(string st)
{
    int id,cnt=0,dk=0;
    trie *ps=root;
    for(int i=0; i<st.size(); i++)
    {
        id=st[i]-'a';
        dk+=!(d[id]-'0');
        if(ps->lnk[id]==NULL)
        {
            ps->lnk[id]=new trie();
            if(dk<=k) cnt++;
        }
        ps=ps->lnk[id];
    }
    return cnt;
}
int main()
{
    cin>>s>>d>>k;
    int ln=s.size();
    root=new trie();
    ans=0;
    for(int i=0; i<ln; i++)
    {
        ans+=trie_insert(s.substr(i,ln-i));
    }
    cout<<ans<<endl;
}
