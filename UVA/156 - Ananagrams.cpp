#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    map<string,int>mp;
    map<string,string>mp1;
    while(getline(cin,s))
    {
        if(s=="#") break;
        stringstream ss;
        ss<<s;
        string c;
        while(ss>>c)
        {
            string cc=c;
            for(int i=0; i<cc.size(); i++) cc[i]=tolower(c[i]);
            sort(cc.begin(),cc.end());
            mp[cc]++;
            mp1[cc]=c;
        }
    }
    vector<string>v;
    for(map<string,int>::iterator it=mp.begin(); it!=mp.end(); it++)
    {
        string c=it->first;
        int cn=it->second;
        if(cn==1) v.push_back(mp1[c]);
    }
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<endl;
    return 0;
}
