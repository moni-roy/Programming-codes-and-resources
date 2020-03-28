#include <bits/stdc++.h>
using namespace std;

int main() {
    int ts,n,m,a,Ans,cs=0;
    cin>>ts;
    while(ts--) {
        cin>>n>>m;
        Ans=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin>>a;
                int t = n-i-1+m-j-1;
                if(t%2) Ans^=a;
            }
        }
        printf("Case %d: ",++cs);
        if(Ans) printf("win\n");
        else printf("lose\n");
    }
    return 0;
}
