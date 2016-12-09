#include <bits/stdc++.h>
using namespace std;
int n,k,a[10040];

int check(int m) {
    int t =0,ret=0;
    for(int i=0; i<=n; i++) {
        if(a[i]>m) return 0;
        if(a[i]+t<=m) {
            t+=a[i];
        } else {
            ret++;
            t=a[i];
        }
    }
    if(t>m) return 0;
    return (k>=ret);
}
int main() {
//    freopen("1048.txt","w",stdout);
    int ts,cs=0,Ans;
    scanf("%d",&ts);
    while(ts--) {
        scanf("%d%d",&n,&k);
        for(int i=0; i<=n; i++) scanf("%d",&a[i]);
        Ans = INT_MAX;
        int l = 0, h = 1e7,m;
        while(l<=h) {
            m = (l+h)>>1;
            if(check(m)) {
                Ans = min(Ans,m);
                h=m-1;
            } else l=m+1;
        }
        printf("Case %d: %d\n",++cs,Ans);
        int t = 0;
        for(int i=0; i<=n; i++) {
            if(t+a[i]<=Ans) {
                if(n-i>=k) t+=a[i];
                else {
                    k--;
                    printf("%d\n",t);
                    t=a[i];
                }

            } else {
                k--;
                printf("%d\n",t);
                t=a[i];
            }
        }
        printf("%d\n",t);
    }
    return 0;
}
/*
2
4 2
5
1
1
1
1
5 4
5
1
5
1
1
1
*/
