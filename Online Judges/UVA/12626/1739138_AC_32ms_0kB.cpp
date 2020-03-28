#include<bits/stdc++.h>

using namespace std;

int main()
{
    string nm;
    int cnt[10],tst,min;
    cin>>tst;
    getchar();
    while(tst--)
    {
        min=100000;
        memset(cnt,0,sizeof(cnt));
        getline(cin,nm);
        int len=nm.size();
        for(int k=0;k<len;k++)
        {
            if(nm[k]=='M') cnt[0]++;
            if(nm[k]=='R') cnt[1]++;
            if(nm[k]=='I') cnt[2]++;
            if(nm[k]=='G') cnt[3]++;
            if(nm[k]=='T') cnt[4]++;
            if(nm[k]=='A') cnt[5]++;
        }
        cnt[5]=cnt[5]/3;
        cnt[1]=cnt[1]/2;
        for(int m=0;m<6;m++)
        {
            if(min>cnt[m]) min=cnt[m];
        }
        cout<<min<<endl;
    }
    return 0;
}
