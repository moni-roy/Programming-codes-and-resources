#include <bits/stdc++.h>
using namespace std;

int sumDg(int n)
{
    int ret=0;
    while(n>0)
    {
        ret+=(n%10);
        n/=10;
    }
    return ret;
}
vector<int>prm;
int vs[1000010];
#define pb push_back
void seive()
{
    prm.pb(2);
    for(int i=3;i<=100000;i+=2){
        if(vs[i]==0)
        {
            prm.pb(i);
            for(int j=i+i;j<=100000;j+=i) vs[j]=1;
        }
    }
    return ;
}
int sumFac(int n)
{
    int ret=0,cn=n;
//    cout<<n<<" ";
    for(int i=0;i<(int)prm.size() && prm[i]*prm[i]<=n;i++)
    {
        if(n%prm[i]==0){
            int cnt=0;
            while(n%prm[i]==0)
            {
                n/=prm[i];
                cnt++;
            }
//            cout<<prm[i]<<"("<<cnt<<")"<<" ";
            ret+=(sumDg(prm[i])*cnt);
        }
    }
    if(n>1){
        ret+=sumDg(n);
    }
    if(n==cn) return -1;
//    cout<<" "<<ret<<endl;
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    seive();
    int ts,n;
    cin>>ts;
    while(ts--)
    {
        cin>>n;
        while(n++)
        {
            if(sumDg(n)==sumFac(n))
            {
                cout<<n<<endl;
                break;
            }
        }
    }
    return 0;
}

