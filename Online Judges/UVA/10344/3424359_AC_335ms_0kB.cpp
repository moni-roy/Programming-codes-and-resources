#include <bits/stdc++.h>
using namespace std;
int st[100],a[100],n,vs[100],ans,flg,snd,trd,frt;
void check()
{
//    for(int i=0;i<5;i++) cout<<st[i]<<" ";
//    cout<<endl;
    for(int i=0; i<3; i++)
    {
        if(i==0) ans=st[0]+st[1];
        else if(i==1) ans=st[0]-st[1];
        else if(i==2) ans=st[0]*st[1];
        for(int j=0; j<3; j++)
        {
            if(j==0) snd=ans+st[2];
            else if(j==1) snd=ans-st[2];
            else if(j==2) snd=ans*st[2];
            for(int k=0; k<3; k++)
            {
                if(k==0) trd=snd+st[3];
                else if(k==1) trd=snd-st[3];
                else if(k==2) trd=snd*st[3];
                for(int l=0; l<3; l++)
                {
                   if(l==0) frt=trd+st[4];
                    else if(l==1) frt=trd-st[4];
                    else if(l==2) frt=trd*st[4];
                    if(frt==23)
                    {
                        flg=1;
                        return ;
                    }
//                    cout<<"+++++++++++++++"<<ans<<endl;
                }
            }
        }
    }
}
void fun(int ps)
{
    if(flg==1) return;
    if(ps==5)
    {
        check();
        return;
    }
    for(int i=0; i<5; i++)
    {
        if(vs[i]==0)
        {
            vs[i]=1;
            st[ps]=a[i];
            fun(ps+1);
            vs[i]=0;
        }
    }
}
int main()
{
    while(cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]&&a[0]&&a[1]&&a[2]&&a[3]&&a[4])
    {
        memset(vs,0,sizeof vs);
        flg=0;
        fun(0);
        if(flg==1) cout<<"Possible"<<endl;
        else cout<<"Impossible"<<endl;
    }
}
