#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ts;
    scanf("%d ",&ts);
    while(ts--)
    {
        string s[111];
        int mp[111][128]={};
        int id=0;
        while(getline(cin,s[id]))
        {
            if(s[id]=="") break;
            id++;
        }
        sort(s,s+id);
        for(int i=0; i<id; i++)
        {
            for(int j=0; j<s[i].size(); j++)
            {
                if(s[i][j]!=' ') mp[i][s[i][j]]++;

            }
        }
        for(int i=0;i<id;i++){
            for(int j=i+1;j<id;j++){
                if(!memcmp(mp[i],mp[j],sizeof(mp[i]))){
                    cout<<s[i]<<" = "<<s[j]<<endl;
                }
            }
        }
        if(ts) cout<<endl;
    }
    return 0;
}
