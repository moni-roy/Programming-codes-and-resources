#include <bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    LL n, a[200005], s = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        s += a[i];
    }
    int id = n;
    if(s >= n) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        int cnt = 0;
        for(int i = n; i >= 1; i--) {
            int t = a[i];
            for(int j = 1; j <= t; j++) {
//                cout << i << " " << id << endl;
                printf("%d %d\n", i, id);
                id--;
                cnt++;
                if(cnt >= 1e6) assert(0);
            }
        }
    }

    return 0;
}
