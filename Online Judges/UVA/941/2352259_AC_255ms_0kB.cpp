#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll fact[25];
    fact[0]=1;
    for(int i=1; i<=25; i++)
    {
        fact[i]=i*fact[i-1];
    }
    ll tst,n;
    string fst;
    cin>>tst;
    while(tst--)
    {
        cin>>fst>>n;
        sort(fst.begin(),fst.end());
        ll ln=fst.size();
        //int cpy=ln;
        //string cpy=fst;
        string snd;
        while(ln)
        {
            ll ind=(n/fact[ln-1]);
            snd+=fst[ind];
            n-=fact[ln-1]*ind;
//            string::iterator it;
//
//            it=fst.begin()+ind;
//            fst.erase(it);
            fst.erase(fst.begin()+ind);
            //cout<<fst<<' '<<ind<<' '<<n<<endl;
            ln--;
        }
        cout<<snd<<endl;
    }
    return 0;
}
