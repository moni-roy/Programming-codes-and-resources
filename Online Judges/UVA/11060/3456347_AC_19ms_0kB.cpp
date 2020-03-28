#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,sv[220][220],ok[220],p,cs=0;
    map<string,int>mp;
    string s[220],ss,sss;
    while(cin>>n)
    {
        memset(sv,0,sizeof sv);
        memset(ok,0,sizeof ok);
        for(int i=1; i<=n; i++)
        {
            cin>>s[i];
            mp[s[i]]=i;
        }
        cin>>p;
        for(int i=0; i<p; i++)
        {
            cin>>ss>>sss;
            //cout<<mp[ss]<<" "<<mp[sss]<<endl;
            if(sv[mp[ss]][mp[sss]]==0)
            {
                sv[mp[ss]][mp[sss]]=1;
                ok[mp[sss]]++;
            }
        }
        cout<<"Case #"<<++cs<<": Dilbert should drink beverages in this order:";
        priority_queue<int>q;
        for(int i=1; i<=n; i++)
        {
            if(ok[i]==0) q.push(-i);
        }
        vector<int>ls;
        while(!q.empty())
        {
            int u=-q.top();
            q.pop();
            ls.push_back(u);
            for(int i=1; i<=n; i++)
            {
                if(sv[u][i]==1)
                {
                    ok[i]--;
                    if(ok[i]==0) q.push(-i);
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            cout<<' '<<s[ls[i]];
        }
        puts(".\n");
        mp.clear();
    }
    return 0;
}
