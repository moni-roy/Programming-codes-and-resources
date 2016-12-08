#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,Ans;
    while(cin>>n && n>=0)
    {
        cout<<n<<" coconuts, ";
        int fl=0;
        for(int i=sqrt(n)+1;i>=2;i--)
        {
            int f=0,cp=n;
            for(int j=0;j<i;j++)
            {
                if(cp%i!=1) f=1;
                if(f) break;
                cp=cp-1-(cp/i);
            }
            if(!f && cp%i==0)
            {
                Ans=i;
                fl=1;
            }
            if(fl) break;
        }
        if(fl) cout<<Ans<<" people and 1 monkey"<<endl;
        else cout<<"no solution"<<endl;
    }
    return 0;
}
