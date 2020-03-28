#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,ts,cs=0,fl,k;
    string s;
    cin>>ts;
    while(ts--){
        cin>>n>>k>>s;
        int Ans=0;
        for(int i=0;i<n;i++){
            fl=0;
            for(int j=i-1;j>=0&&j>=i-k;j--){
                if(s[i]==s[j]) fl=1;
            }
            if(fl) Ans++;
        }
        cout<<"Case "<<++cs<<": "<<Ans<<endl;
    }
    return 0;
}
