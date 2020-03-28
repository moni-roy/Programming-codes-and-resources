#include <bits/stdc++.h>
using namespace std;
int a[100],cp;
string st;
int main()
{
    while(cin>>a[0])
    {
        for(int i=1; i<9; i++) cin>>a[i];

        st="";
        for(int i=0; i<8; i++)
        {
            if(a[i]==0) continue;
            if(a[i]<0)
            {
                if(st.size()==0) st+='-';
                else
                {
                    st+=' ';
                    st+='-';
                    st+=' ';
                }
            }
            else if(a[i]>0)
            {
                if(st.size()!=0)
                {
                    st+=' ';
                    st+='+';
                    st+=' ';
                }
            }
            a[i]=abs(a[i]);
            if(a[i]!=1)
            {
                cp=a[i];
                string s="";
                while(cp>0)
                {
                    s+=(cp%10+'0');
                    cp/=10;
                }
                for(int m=s.size()-1; m>=0; m--) st+=s[m];
            }
            st+='x';
            if(8-i>1)
            {
                st+='^';
                st+=((8-i)+'0');
            }
        }
        int flg=0;
        if(a[8]!=0)
        {
            if(st.size()==0)
            {
                flg=1;
                cout<<a[8]<<endl;
            }
            if(a[8]<0)
            {
                st+=' ';
                st+='-';
                st+=' ';
            }
            else if(a[8]>0)
            {
                st+=' ';
                st+='+';
                st+=' ';
            }
            cp=abs(a[8]);
            string s="";
            while(cp>0)
            {
                s+=(cp%10+'0');
                cp/=10;
            }
            for(int m=s.size()-1; m>=0; m--) st+=s[m];
        }
        if(st.size()&&flg==0)
            cout<<st<<endl;
        else if(st.size()==0&&flg==0) cout<<0<<endl;
    }
}
