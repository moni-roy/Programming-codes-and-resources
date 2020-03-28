#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct st
{
    st *a[3];
    int cnt;

}*root;

ll insert_trie(string s)
{
    int id,ret=0;
    st *p=root;
    for(int i=0;i<s.size();i++)
    {
        id=s[i]-'0';
        if(p->a[id]==NULL)
        {
            p->a[id]=new st();
        }
        p=p->a[id];
        p->cnt=p->cnt+1;
        ret=max(ret,p->cnt*(i+1));
    }
    return ret;
}
int main()
{
    int t,n,ret,ans;
    string s;
    cin>>t;
    while(t--)
    {
        root =new st();
        cin>>n;
        ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            ret=insert_trie(s);
            ans=max(ans,ret);
        }
        cout<<ans<<endl;
    }
}
