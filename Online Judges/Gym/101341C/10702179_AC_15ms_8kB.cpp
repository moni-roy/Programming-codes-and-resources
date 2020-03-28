#include <bits/stdc++.h>
using namespace std;

#define LL long long

LL a, b, c;
LL n, m;

int ok(LL d) {
    LL p = min(a + c, d);
    if(p > n) return 0;
    p = min(b + c, d);
    if(p > m) return 0;
    return 1;
}

int main() {
    cin >> a >> b >> c;
    cin >> n >> m;
    LL lo = 0, hi = a + b + c, best = 0;
    while(lo <= hi) {
        LL mid = (lo + hi) / 2;
        if(ok(mid)) {
            lo = mid + 1;
            best = mid;
        } else hi = mid - 1;
    }
    cout << best << endl;
    return 0;
}
