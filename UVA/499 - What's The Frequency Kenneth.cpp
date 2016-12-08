#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{

    string str;

    while(getline(cin,str))
    {
        int mx=0;
        map<int,int>mk;
        int len=str.length();
        for(int i=0;i<len;i++)
        {
            if(str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z')
            {
                mk[str[i]]++;
            }
            mx=max(mx,mk[str[i]]);
        }
        for(int i=40;i<150;i++)
        {
            if(mk[i]==mx) printf("%c",i);
        }
        cout<<' '<<mx<<endl;
    }
    return 0;
}
