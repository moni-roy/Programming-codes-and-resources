#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int N = 1e3 + 5, M = 1e9 + 7;

int n, m, a[N][N], b[N][N];
int vr[N], vc[N];

int seg[2][N][4 * N];

void update(int f, int d, int c, int s, int e, int p, int v) {
    if(s == e) {
        seg[f][d][c] = v;
        return;
    }
    int L = 2 * c, R = L + 1, m = (s + e) / 2;
    if(p <= m) update(f, d, L, s, m, p, v);
    else update(f, d, R, m + 1, e, p, v);
    seg[f][d][c] = max(seg[f][d][L], seg[f][d][R]);
}

//int query(int f, int d, int c, int s, int e, int l, int r){
//
//}

int main() {
    int mx = 0, r = -1, c = -1;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
            mx = max(mx, a[i][j]);
            update(0, i, 1, 1, m, j, a[i][j]);
            update(1, j, 1, 1, n, i, a[i][j]);
        }
    }
    int rr = -1, cc = -1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j] == mx) {
                vr[i]++;
                vc[j]++;
                rr = i, cc = j;
            }
        }
    }
    int R = -1, C = -1;
    for(int i = 1; i <= n; i++) {
        if(vr[i] > 1) {
            // row must
            R = i;
        }
    }
    for(int i = 1; i <= m; i++) {
        if(vc[i] > 1) {
            // row must
            C = i;
        }
    }
    if(R == -1 || C == -1) {
        if(R != -1 && C == -1) {
            for(int j = 1; j <= m; j++) {
                update(1, j, 1, 1, n, R, 0);
            }
            int mn = 0, ic = -1;;
            for(int j = 1; j <= m; j++) {
                if(seg[1][j][1] > mn) {
                    mn = seg[1][j][1];
                    ic = j;
                }
            }
            printf("%d %d\n", R, ic);
        } else if(R == -1 && C != -1) {
            for(int i = 1; i <= n; i++) {
                update(0, i, 1, 1, m, C, 0);
            }
            int mn = 0, ic = -1;;
            for(int j = 1; j <= n; j++) {
                if(seg[0][j][1] > mn) {
                    mn = seg[0][j][1];
                    ic = j;
                }
            }
            printf("%d %d\n", ic, C);
        } else {
            // row fix
            R = rr;
            for(int j = 1; j <= m; j++) {
                update(1, j, 1, 1, n, R, 0);
            }
            int mn = 0, ic = -1;;
            for(int j = 1; j <= m; j++) {
                if(seg[1][j][1] > mn) {
                    mn = seg[1][j][1];
                    ic = j;
                }
            }
//            cout << mn << " -> " << ic << endl;
            mx = 0;
            for(int j = 1; j <= m; j++) {
                if(j == ic) continue;
                mx = max(mx, seg[1][j][1]);

            }
//            cout << R << " * " << ic << endl;
//            cout << mx << endl;
//            for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) {
                update(1, j, 1, 1, n, R, a[R][j]);
            }
//            cout << rr << " " << cc << endl;
            // column fix
            C = cc;
            for(int i = 1; i <= n; i++) {
                update(0, i, 1, 1, m, C, 0);
            }
            int mm = 0, ir = -1;;
            for(int j = 1; j <= n; j++) {
                if(seg[0][j][1] > mm) {
                    mm = seg[0][j][1];
                    ir = j;
                }
            }
//            cout << "MN " << mm << " " << ir << endl;
            mm = 0;
            for(int j = 1; j <= n; j++) {
                if(j == ir) continue;
                mm = max(mm, seg[0][j][1]);
            }
//            cout << mm << " # " << mx << endl;
            if(mm < mx) {
                printf("%d %d\n", ir, C);
            } else printf("%d %d\n", R, ic);

        }
    } else printf("%d %d\n", R, C);
    return 0;
}
