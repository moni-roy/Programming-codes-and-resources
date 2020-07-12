#include <bits/stdc++.h>
using namespace std;

int main() {
    int ts,cs = 0, n, a[200010];
    cin>>ts;
    while(ts--) {
        cin>>n;
        for(int i = 0;i<n;i++) cin>>a[i];
        a[n]=-1;
        int mx = -1, Ans = 0;
        for(int i = 0;i<n;i++) {
            if(a[i]>mx && a[i]>a[i+1]) {
                Ans ++;
                mx = a[i];
            }
            mx = max(mx, a[i]);
        }
        cout<<"Case #"<<++cs<<": "<<Ans<<endl;
    }
}